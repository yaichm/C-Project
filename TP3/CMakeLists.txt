cmake_minimum_required(VERSION 3.16.3)
project(TP3)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(CMAKE_CXX_FLAGS "-Wextra -Wall -g -pg -O2")
add_executable(Simulation_TP3 
    src/vecteur.cxx 
    src/main.cxx 
    src/univers.cxx 
    src/particuleA.cxx 
    src/StormerVerlet.cxx)
