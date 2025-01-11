cmake_minimum_required(VERSION 3.26)
project(CoMdAutograd LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)

add_executable(app main.c
        src/read_csv.c)
