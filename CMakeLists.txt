project(Slae)

cmake_minimum_required(VERSION 3.0)

enable_testing()
find_package(GTest REQUIRED)

add_library(progonka src/progonka.h src/progonka.cpp)
add_library(three_diag_table src/three_diag_table.h src/three_diag_table.cpp)
add_executable(test3 test/test3.cpp)


target_link_libraries(test3 GTest::gtest progonka three_diag_table)


