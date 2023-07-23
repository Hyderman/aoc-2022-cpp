enable_testing()

find_package(GTest CONFIG REQUIRED)
add_executable(day1_tests day1-tests.cpp)
target_link_libraries(day1_tests PRIVATE GTest::gtest GTest::gtest_main)

add_test(day1_gtest day1_tests)
