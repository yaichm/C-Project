cmake_minimum_required(VERSION 3.10)
project(TP4)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -DNDEBUG -Wall")
add_executable(main
    src/main.cxx
    src/univers.cxx
    src/cellule.cxx
    src/particule.cxx 
    src/vecteur.cxx
)


add_executable(simulation
    src/simulation.cxx
    src/univers.cxx
    src/cellule.cxx
    src/particule.cxx 
    src/vecteur.cxx
)
