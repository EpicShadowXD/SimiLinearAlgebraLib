cmake_minimum_required(VERSION 3.24)
project(LinearAlgebraLib)

set(CMAKE_CXX_STANDARD 23)

add_executable(LinearAlgebraLib main.cpp Matrix.cpp Matrix.h LinearAlgebra.cpp Iterator.cpp)
