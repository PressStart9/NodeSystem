include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.16.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(node_tests
        data_node_test.cpp
        control_node_test.cpp
)

target_link_libraries(node_tests PRIVATE
        GTest::gtest
        GTest::gtest_main
        node_system
)

include(GoogleTest)

gtest_discover_tests(node_tests)
