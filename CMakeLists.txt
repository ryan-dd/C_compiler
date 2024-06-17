cmake_minimum_required(VERSION 3.19)
project(Compiler)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)

add_library(${PROJECT_NAME} src/compiler.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
  src/
)

add_executable(main main.cpp)
target_link_libraries(main ${PROJECT_NAME})
