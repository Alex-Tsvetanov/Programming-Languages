cmake_minimum_required(VERSION 3.15...3.30)

project(
  ProgrammingLanguages
  VERSION 1.0
  LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 11)

add_executable(lab1_task1 lab1/task1.cpp)
target_compile_options(lab1_task1 PUBLIC -O0)

add_subdirectory(project)
