cmake_minimum_required(VERSION 3.14)
project(TP5)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests
  tests/vecteur_test.cxx
  tests/particules_test.cxx
  src/vecteur.cxx 
)

target_include_directories(tests PRIVATE include)

target_link_libraries(tests
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
