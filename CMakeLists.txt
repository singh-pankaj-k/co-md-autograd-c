cmake_minimum_required(VERSION 3.26)
project(CoMdAutograd LANGUAGES C CXX)
set(CMAKE_C_STANDARD 11)

# Enable testing
enable_testing()

# Add the main source files
add_library(my_code src/add.c src/add.h)

file(GLOB SRC_FILES "src/*.c" "src/*.h")

add_executable(
        app
        ${SRC_FILES}
)

# Add the test executable
add_executable(test_add test/test_add.c)

# Link the test executable with the main code (no external libraries needed)
target_link_libraries(test_add my_code)

# Add test to CTest
add_test(NAME test_add COMMAND test_add)

#MESSAGE("HI I AM PRINTING")
#message(${SRC_FILES})
