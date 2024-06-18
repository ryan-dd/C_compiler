find_package(GTest REQUIRED)

add_executable(test${PROJECT_NAME} src/TokenizerTests.cpp)
target_link_libraries(test${PROJECT_NAME} PRIVATE GTest::gtest_main ${PROJECT_NAME})
include(GoogleTest)
gtest_discover_tests(test${PROJECT_NAME})

