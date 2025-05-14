cmake_minimum_required(VERSION 3.22)

project(MyProject)

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

# include_directories(${PROJECT_SOURCE_DIR}/../../../libs/matplotlib-cpp)

include_directories(${Python3_INCLUDE_DIRS})

include_directories(include)
# add_executable(lj_plot src/lj_plot.cxx)

add_executable(main src/main.cxx)

# target_link_libraries(lj_plot PRIVATE ${Python3_LIBRARIES})

