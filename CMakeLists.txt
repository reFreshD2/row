cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(row config.h cpp_accumulator.cpp experiments.h interface.h num_threads.cpp num_threads.h omp_accumulator.c run_experiments.cpp Source.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fopenmp")