cmake_minimum_required(VERSION 3.26)
project(CoMdAutograd LANGUAGES C CXX)
set(CMAKE_C_STANDARD 11)

file(GLOB SRC_FILES "src/*.c" "src/*.h")

add_executable(
        app
        ${SRC_FILES}
)

# Enable testing
enable_testing()

# Add the main source files
add_library(add_lib src/add.c src/add.h)
add_library(read_csv_lib src/read_csv.c src/add.h)

# Add the test executable
add_executable(test_add test/test_add.c)
add_executable(test_read_csv test/test_read_csv.c)

# Link the test executable with the main code (no external libraries needed)
target_link_libraries(test_add add_lib)
target_link_libraries(test_read_csv read_csv_lib)

# Add test to CTest
add_test(NAME test_add COMMAND test_add)
add_test(NAME test_read_csv COMMAND test_read_csv)

#MESSAGE("HI I AM PRINTING")
#message(${SRC_FILES})
