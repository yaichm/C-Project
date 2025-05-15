cmake_minimum_required(VERSION 3.10)
project(TP4)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(main
    src/main.cxx
    src/univers.cxx
    src/cellule.cxx
    src/particule.cxx 
    src/vecteur.cxx
)
