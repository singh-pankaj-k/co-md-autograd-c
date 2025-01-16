cmake_minimum_required(VERSION 3.26)
project(CoMdAutograd LANGUAGES C CXX)
set(CMAKE_C_STANDARD 17)

# Find the GSL package
find_package(GSL REQUIRED)

file(GLOB SRC_FILES "src/*.c" "src/*.h")

add_executable(
        app
        ${SRC_FILES}
)

# Include GSL headers and link the library
target_include_directories(app PRIVATE ${GSL_INCLUDE_DIRS})
target_link_libraries(app PRIVATE ${GSL_LIBRARIES})

# Enable testing
enable_testing()

# Add the main source files
add_library(value_lib src/value.c src/value.h)
add_library(tensor_lib src/tensor.c src/tensor.h)
add_library(read_csv_lib src/read_csv.c src/tensor.h)

# Add the test executable
add_executable(test_value test/test_value.c)
add_executable(test_tensor test/test_tensor.c)
add_executable(test_read_csv test/test_read_csv.c)

# Link the test executable with the main code (no external libraries needed)
target_link_libraries(test_value value_lib)
target_link_libraries(test_tensor tensor_lib)
target_link_libraries(test_read_csv read_csv_lib)

# Add test to CTest
add_test(NAME test_value COMMAND test_value)
add_test(NAME test_tensor COMMAND test_tensor)
add_test(NAME test_read_csv COMMAND test_read_csv)

#MESSAGE("HI I AM PRINTING")
#message(${SRC_FILES})
