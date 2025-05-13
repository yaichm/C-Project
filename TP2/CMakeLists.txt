cmake_minimum_required(VERSION 3.16.3)
project(Particule)
set(CMAKE_CXX_STANDARD 17)
include_directories(include)
set(CMAKE_CXX_FLAGS "-Wall -Wextra  -g -pg -O2")
add_executable(Simulation 
    src/ParticuleA.cpp
    src/StormerVerlet.cpp
    src/main.cpp)
# Create a static library from TP2 sources
add_library(tp2_lib
    src/ParticuleA.cpp
    src/StormerVerlet.cpp
)
target_include_directories(tp2_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
