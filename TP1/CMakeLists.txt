cmake_minimum_required (VERSION 3.16.3)
project(Demo CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wextra -Wall -O2")

# Commentaire

add_executable(exe trace.cxx)
add_executable(euler euler.cxx)
