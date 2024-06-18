cmake_minimum_required(VERSION 3.19)
project(Compiler)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)

add_library(${PROJECT_NAME} 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/File.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Tokenizer.cpp
  )
target_include_directories(${PROJECT_NAME} PUBLIC
  src/
)

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/CompilerWarnings.cmake")
set_project_warnings(${PROJECT_NAME})

add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(main ${PROJECT_NAME})

option(CCOMPILER_BUILD_TESTS "Enable building tests." ON)

if(CCOMPILER_BUILD_TESTS)
  enable_testing()
  add_subdirectory(test)
endif()
