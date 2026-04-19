include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# ── Helper to register a test binary ─────────────────────────────────────────
# Usage: add_gtest(NAME db_client_test SOURCES db/db_client_test.cpp LIBS db_lib)
function(add_gtest)
    cmake_parse_arguments(ARG "" "NAME" "SOURCES;LIBS" ${ARGN})
    add_executable(${ARG_NAME} ${ARG_SOURCES})
    target_link_libraries(${ARG_NAME} PRIVATE
        GTest::gtest_main
        GTest::gmock
        ${ARG_LIBS}
    )
    target_include_directories(${ARG_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_BINARY_DIR}/src/protos
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
    gtest_discover_tests(${ARG_NAME}
        DISCOVERY_MODE PRE_TEST    # ← discover at test time not configure time
    )
endfunction()

# ── Register tests (add one line per test binary) ────────────────────────────
# add_gtest(
#     NAME    service_client_test
#     SOURCES 
#         service/client_test.cpp 
#         service/client_health_test.cpp 
#     LIBS    project_proto
#             gRPC::grpc++
# )

# Add proto_gen include path to the test target
# target_include_directories(service_client_test PRIVATE
#     ${CMAKE_BINARY_DIR}/proto_gen
# )

# add_gtest(NAME db_client_test  SOURCES db/db_client_test.cpp  LIBS db_lib)
# add_gtest(NAME grpc_service_test SOURCES grpc/my_service_test.cpp LIBS grpc_lib)