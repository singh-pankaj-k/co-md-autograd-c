cmake_minimum_required(VERSION 3.26)
project(CoMdAutograd LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)

file(GLOB SRC_FILES "*.c" "src/*.c" "src/*.h")

add_executable(
        app
        ${SRC_FILES}
)


#MESSAGE("HI I AM PRINTING")
#message(${SRC_FILES})
