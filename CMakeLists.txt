cmake_minimum_required(VERSION 3.30)
project(GaussianElim)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
add_executable(GaussianElim main.cpp myMatrix.cpp)
