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
# DEPENDENCY DISCOVERY
# =============================================================================
function(find_package_dependencies)
    find_package(Protobuf CONFIG REQUIRED)
    find_package(gRPC CONFIG REQUIRED)
    find_package(PostgreSQL)

    if(NOT PostgreSQL_FOUND)
        message(WARNING "PostgreSQL not found — disabling DB features")
    endif()

    find_package(Qt6 6.2 REQUIRED COMPONENTS Core Gui Widgets Qml Quick QuickControls2 QmlIntegration)
    find_package(Doxygen)
endfunction()

find_package_dependencies()

# =============================================================================
# EIGEN (pinned to 3.4.0 — required by RBDL, incompatible with Eigen 5.x)
# =============================================================================
FetchContent_Declare(
    eigen
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG 3.4.0
    GIT_SHALLOW TRUE
)

# Eigen's CMakeLists doesn't define an install target we need — just make headers available
FetchContent_MakeAvailable(eigen)
set_property(DIRECTORY "${eigen_SOURCE_DIR}" PROPERTY EXCLUDE_FROM_ALL TRUE)
set(EIGEN_BUILD_DOC OFF CACHE BOOL "" FORCE)
set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
set(EIGEN_BUILD_TESTING OFF CACHE BOOL "" FORCE)
set(EIGEN_BUILD_UNITTESTS OFF CACHE BOOL "" FORCE)
set_property(DIRECTORY ${eigen_SOURCE_DIR} PROPERTY CMAKE_AUTOMOC OFF)
set_property(DIRECTORY ${eigen_SOURCE_DIR} PROPERTY CMAKE_AUTORCC OFF)
set(EIGEN3_INCLUDE_DIR ${eigen_SOURCE_DIR} CACHE PATH "Eigen3 headers" FORCE)
message(STATUS "Using fetched Eigen3 from: ${EIGEN3_INCLUDE_DIR}")

# =============================================================================
# EXTERNAL DEPENDENCIES (FETCHCONTENT)
# =============================================================================
FetchContent_Declare(
    cli11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.4.2
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(cli11)

FetchContent_Declare(
    rang
    GIT_REPOSITORY https://github.com/agauniyal/rang.git
    GIT_TAG master
    GIT_SHALLOW TRUE
)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
FetchContent_MakeAvailable(rang)

set(CGAL_DO_NOT_WARN_ABOUT_CMAKE_BUILD_TYPE TRUE)

FetchContent_Declare(
    rbdl
    GIT_REPOSITORY https://github.com/rbdl/rbdl.git
    GIT_TAG v3.2.0
    GIT_SHALLOW TRUE
)
set(RBDL_BUILD_STATIC OFF CACHE BOOL "" FORCE)
set(RBDL_BUILD_TESTS OFF CACHE BOOL "" FORCE)

# Tell RBDL NOT to search for system Eigen — we supply EIGEN3_INCLUDE_DIR directly
set(RBDL_USE_SYSTEM_EIGEN OFF CACHE BOOL "" FORCE)

# Patch rbdl's Eigen search before it runs
set(EIGEN3_INCLUDE_DIR ${eigen_SOURCE_DIR} CACHE PATH "" FORCE)
FetchContent_MakeAvailable(rbdl)

# Ensure rbdl picks up our Eigen headers (it uses EIGEN3_INCLUDE_DIR internally)
target_include_directories(rbdl PUBLIC ${eigen_SOURCE_DIR})

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
        "Run `scripts/gen_proto.sh` before configuring."
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
    else()
        add_library(${ARG_NAME} INTERFACE)
    endif()

    target_include_directories(${ARG_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )
    target_link_libraries(${ARG_NAME}
        PUBLIC ${ARG_LIBS}
        PRIVATE ${ARG_PRIVATE_LIBS}
    )
endfunction()

# =============================================================================
# LIBRARIES  (uncomment as you add code)
# =============================================================================

# add_auto_library(NAME utils
# LIBS CLI11::CLI11 rang project_proto
# )
# set_target_properties(utils PROPERTIES POSITION_INDEPENDENT_CODE ON)

# add_auto_library(NAME geometry
# LIBS Eigen3::Eigen project_proto utils
# )

# add_auto_library(NAME dynamics
# LIBS rbdl Eigen3::Eigen project_proto utils
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
    ${eigen_SOURCE_DIR}
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
# QML MODULE
# =============================================================================
qt_add_qml_module(Workspace
    URI com.myapp
    VERSION 1.0
    NO_PLUGIN
    OUTPUT_TARGETS qml_module_targets
    QML_FILES
    qml/Main.qml
)

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