//
// Created by Pankaj Priscilla on 2025-01-11.
//

// test/test_add.c
#include <assert.h>
#include "../src/tensor.h"

int main() {
    // Test the add function
    assert(add(1, 2) == 3);        // Test case 1: 1 + 2 = 3
    assert(add(-1, 2) == 1);       // Test case 2: -1 + 2 = 1
    assert(add(0, 0) == 0);        // Test case 3: 0 + 0 = 0
    assert(add(100, 200) == 300); // Test case 4: 100 + 200 = 300
    return 0; // Return success if all tests pass
}
