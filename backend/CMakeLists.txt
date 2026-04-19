cmake_minimum_required(VERSION 3.28)
project(project LANGUAGES CXX)

if(APPLE)
    execute_process(
        COMMAND xcrun --show-sdk-path
        OUTPUT_VARIABLE SDK_PATH
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    message(STATUS "Using macOS SDK: ${SDK_PATH}")
    set(CMAKE_OSX_SYSROOT ${SDK_PATH})
    add_compile_options(-isysroot ${SDK_PATH} -stdlib=libc++)
    add_link_options(-isysroot ${SDK_PATH} -stdlib=libc++)
endif()

cmake_policy(SET CMP0144 NEW)

# Suppress deprecated FetchContent_Populate warning on cmake 3.28
cmake_policy(SET CMP0169 OLD)

# =============================================================================
# GLOBAL CONFIGURATION
# =============================================================================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

include(FetchContent)

# =============================================================================
# STEP 1 — FETCH NON-QT DEPENDENCIES FIRST
# RBDL's cmake calls find_package(Eigen3) internally which corrupts Qt's
# internal policy registry (_qt_known_policies). All non-Qt FetchContent
# must complete before Qt6 is loaded via find_package.
# =============================================================================

# ----- Eigen 3.4.0 (header-only, do NOT run its subdirs) --------------------
set(EIGEN_BUILD_DOC OFF CACHE BOOL "" FORCE)
set(EIGEN_BUILD_TESTING OFF CACHE BOOL "" FORCE)
set(EIGEN_BUILD_PKGCONFIG OFF CACHE BOOL "" FORCE)
set(BUILD_TESTING OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    eigen
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG 3.4.0
    GIT_SHALLOW TRUE
)
FetchContent_GetProperties(eigen)

if(NOT eigen_POPULATED)
    FetchContent_Populate(eigen) # download only — no add_subdirectory
endif()

set(EIGEN3_INCLUDE_DIR ${eigen_SOURCE_DIR} CACHE PATH "Eigen3 headers" FORCE)
message(STATUS "Using fetched Eigen3 from: ${EIGEN3_INCLUDE_DIR}")

add_library(Eigen3_headers INTERFACE)
target_include_directories(Eigen3_headers INTERFACE ${EIGEN3_INCLUDE_DIR})

# ----- CLI11 -----------------------------------------------------------------
FetchContent_Declare(
    cli11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.4.2
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(cli11)

# ----- rang ------------------------------------------------------------------
FetchContent_Declare(
    rang
    GIT_REPOSITORY https://github.com/agauniyal/rang.git
    GIT_TAG master
    GIT_SHALLOW TRUE
)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
FetchContent_MakeAvailable(rang)

set(CGAL_DO_NOT_WARN_ABOUT_CMAKE_BUILD_TYPE TRUE)

# ----- RBDL ------------------------------------------------------------------
set(RBDL_BUILD_STATIC OFF CACHE BOOL "" FORCE)
set(RBDL_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(RBDL_USE_SYSTEM_EIGEN OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    rbdl
    GIT_REPOSITORY https://github.com/rbdl/rbdl.git
    GIT_TAG v3.2.0
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(rbdl)

# Suppress -Wreorder-ctor in RBDL (third-party code, not our bug)
FetchContent_GetProperties(rbdl)

if(rbdl_POPULATED)
    set_property(DIRECTORY ${rbdl_SOURCE_DIR}
        PROPERTY COMPILE_OPTIONS "-Wno-reorder-ctor"
    )

    # Mark RBDL includes as SYSTEM to suppress warnings from its headers
    get_target_property(_rbdl_inc rbdl INTERFACE_INCLUDE_DIRECTORIES)
    set_target_properties(rbdl PROPERTIES
        INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "${_rbdl_inc}"
    )
endif()

target_include_directories(rbdl PUBLIC ${EIGEN3_INCLUDE_DIR})

# =============================================================================
# STEP 2 — LOAD Qt6 LAST so its policy registry is not corrupted by RBDL
# =============================================================================
find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(PostgreSQL)

if(NOT PostgreSQL_FOUND)
    message(WARNING "PostgreSQL not found — disabling DB features")
endif()

find_package(Qt6 6.2 REQUIRED COMPONENTS Core Gui Qml Quick QuickControls2)
find_package(Doxygen)

# =============================================================================
# PROTO LIBRARY
# =============================================================================
file(GLOB_RECURSE PROTO_GENERATED_SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/protos/*.cc"
)

if(PROTO_GENERATED_SOURCES)
    add_library(project_proto STATIC ${PROTO_GENERATED_SOURCES})
    target_include_directories(project_proto PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/protos
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )
    target_link_libraries(project_proto PUBLIC
        gRPC::grpc++
        protobuf::libprotobuf
    )
    target_compile_definitions(project_proto PRIVATE
        PROTOBUF_USE_DLLS
        ABSL_MIN_LOG_LEVEL=100
        GOOGLE_PROTOBUF_NO_LOGGING
    )
else()
    message(WARNING
        "No generated proto sources found in backend/src/protos/. "
        "Run scripts/gen_proto.sh before configuring."
    )
    add_library(project_proto INTERFACE)
endif()

# =============================================================================
# HELPER: AUTO LIBRARY CREATION
# =============================================================================
function(add_auto_library)
    cmake_parse_arguments(ARG "" "NAME;LINKING" "LIBS;PRIVATE_LIBS" ${ARGN})

    if(NOT ARG_LINKING)
        set(ARG_LINKING STATIC)
    endif()

    file(GLOB_RECURSE SOURCES
        CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/${ARG_NAME}/*.cpp
    )

    if(SOURCES)
        add_library(${ARG_NAME} ${ARG_LINKING} ${SOURCES})

        target_include_directories(${ARG_NAME} PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/src
        )

        target_link_libraries(${ARG_NAME}
            PUBLIC ${ARG_LIBS}
            PRIVATE ${ARG_PRIVATE_LIBS}
        )
    else()
        # No .cpp files yet — create a header-only interface target
        # so link dependencies still resolve correctly
        add_library(${ARG_NAME} INTERFACE)
        target_include_directories(${ARG_NAME}
            INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src
        )
        target_link_libraries(${ARG_NAME}
            INTERFACE ${ARG_LIBS}
        )
        set_target_properties(${ARG_NAME} PROPERTIES INTERFACE_LINK_LIBRARIES "${ARG_LIBS}")

        message(STATUS "add_auto_library: ${ARG_NAME} has no sources, created INTERFACE target")
    endif()
endfunction()

# =============================================================================
# LIBRARIES  (uncomment as you add source files)
# =============================================================================
add_auto_library(NAME utilities
    LIBS CLI11::CLI11 rang project_proto
)

set_target_properties(utilities PROPERTIES POSITION_INDEPENDENT_CODE ON)

# add_auto_library(NAME geometry
# LIBS Eigen3_headers project_proto utils
# )
# add_auto_library(NAME dynamics
# LIBS rbdl Eigen3_headers project_proto utils
# )
# add_auto_library(NAME commands
# LIBS geometry dynamics
# LINKING SHARED
# )
# add_auto_library(NAME service
# LIBS gRPC::grpc++ project_proto commands
# )

# =============================================================================
# EXECUTABLE
# =============================================================================
add_executable(Workspace src/main.cpp)

target_include_directories(Workspace PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/protos
    ${EIGEN3_INCLUDE_DIR}
)

target_link_libraries(Workspace PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickControls2
    project_proto
    rbdl
    CLI11::CLI11
)

target_compile_options(Workspace PRIVATE
    -Wall -Wextra -Wpedantic -Werror
)

# =============================================================================
# QML MODULE — Qt6 is loaded fresh above so QTP0005 policy is registered
# =============================================================================
qt_policy(SET QTP0001 NEW)
qt_policy(SET QTP0004 NEW)

qt_add_qml_module(Workspace
    URI com.myapp
    VERSION 1.0
    NO_PLUGIN
    OUTPUT_TARGETS qml_module_targets
    QML_FILES
    src/qml/Main.qml
)

# =============================================================================
# DEBUG OPTIONS
# =============================================================================
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(Workspace PRIVATE
        -g -O0 -fno-omit-frame-pointer
        -fsanitize=address,undefined
    )
    target_link_options(Workspace PRIVATE
        -fsanitize=address,undefined
    )
endif()

# =============================================================================
# TESTING
# =============================================================================
enable_testing()
add_subdirectory(tests)

# =============================================================================
# OPTIONAL DOCS
# =============================================================================
if(DOXYGEN_FOUND)
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_GENERATE_XML YES)
    doxygen_add_docs(docs src/ README.md)
endif()