cmake_minimum_required(VERSION 3.28)
project(project LANGUAGES CXX)

cmake_policy(SET CMP0144 NEW)

# =============================================================================
# GLOBAL CONFIGURATION
# =============================================================================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

# =============================================================================
# DEPENDENCY DISCOVERY
# =============================================================================

function(find_package_dependencies)
    find_package(Protobuf CONFIG REQUIRED)
    find_package(gRPC CONFIG REQUIRED)
    find_package(PostgreSQL REQUIRED)
    find_package(Eigen3 REQUIRED NO_MODULE)
    find_package(Doxygen)
endfunction()

find_package_dependencies()

# =============================================================================
# EXTERNAL DEPENDENCIES (FETCHCONTENT)
# =============================================================================

FetchContent_Declare(
    cli11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.4.2
)
FetchContent_MakeAvailable(cli11)

FetchContent_Declare(
    rang
    GIT_REPOSITORY https://github.com/agauniyal/rang.git
    GIT_TAG master
)
# Override rang's ancient cmake_minimum_required
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
FetchContent_MakeAvailable(rang)

FetchContent_Declare(
    cgal
    GIT_REPOSITORY https://github.com/CGAL/cgal.git
    GIT_TAG v5.6.1
)
FetchContent_MakeAvailable(cgal)
set(CGAL_DO_NOT_WARN_ABOUT_CMAKE_BUILD_TYPE TRUE)

FetchContent_Declare(
    rbdl
    GIT_REPOSITORY https://github.com/rbdl/rbdl.git
    GIT_TAG v3.2.0
)
set(RBDL_BUILD_STATIC OFF CACHE BOOL "" FORCE)
set(RBDL_BUILD_TESTS  OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(rbdl)

# =============================================================================
# PROTO LIBRARY  (consumes pre-generated files — run scripts/gen_protos.sh first)
# =============================================================================

file(GLOB_RECURSE PROTO_GENERATED_SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/protos/*.cc"
)

if(PROTO_GENERATED_SOURCES)
    add_library(project_proto STATIC
        ${PROTO_GENERATED_SOURCES}
        src/proto/absl_fix.cpp
    )

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
        "Run `scripts/gen_protos.sh cpp` before configuring."
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
        PUBLIC  ${ARG_LIBS}
        PRIVATE ${ARG_PRIVATE_LIBS}
    )
endfunction()

# =============================================================================
# LIBRARIES
# =============================================================================

# add_auto_library(NAME utils
#     LIBS CLI11::CLI11 rang project_proto
# )
# set_target_properties(utils PROPERTIES POSITION_INDEPENDENT_CODE ON)

# add_auto_library(NAME geometry
#     LIBS CGAL::CGAL Eigen3::Eigen project_proto utils
# )

# add_auto_library(NAME dynamics
#     LIBS rbdl Eigen3::Eigen project_proto utils
# )

# add_auto_library(NAME commands
#     LIBS geometry dynamics
#     LINKING SHARED
# )

# add_auto_library(NAME service
#     LIBS gRPC::grpc++ project_proto commands
# )

# =============================================================================
# EXECUTABLE
# =============================================================================

add_executable(Workspace
    src/main.cpp
)

target_include_directories(Workspace PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/protos
)

target_link_libraries(Workspace PRIVATE
    service
    commands
    dynamics
    geometry
    utils
    project_proto
    gRPC::grpc++_reflection
    PostgreSQL::PostgreSQL
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