cmake_minimum_required(VERSION 3.14)
project(AbstractVM)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wconversion")
#set(CMAKE_CXX_STANDARD 98)

add_executable(AbstractVM main.cpp IOperand.hpp)