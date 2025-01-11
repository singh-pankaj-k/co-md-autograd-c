cmake_minimum_required(VERSION 3.26)
project(NeuralNet C)

set(CMAKE_C_STANDARD 11)

add_executable(NeuralNet main.c
        src/read_csv.c)
