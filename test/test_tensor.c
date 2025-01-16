//
// Created by Pankaj Priscilla on 2025-01-11.
//

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "../src/tensor.h"

int test_tensor() {
    // Test the tensor declaration
    Tensor tensor = {
       .data = NULL,
       .grad = NULL,
       .shape = NULL,
       .strides = NULL,
       .ndim = 0,
       .size = 0,
       .parent1 = NULL,
       .parent2 = NULL,
       .backward = NULL,
       .requires_grad = 0
    };

    assert(tensor.data == NULL);
    assert(tensor.grad == NULL);
    assert(tensor.shape == NULL);
    assert(tensor.strides == NULL);
    assert(tensor.ndim == 0);
    assert(tensor.size == 0);
    assert(tensor.parent1 == NULL);
    assert(tensor.parent2 == NULL);
    assert(tensor.backward == NULL);
    assert(tensor.requires_grad == 0);
    return 0;
}


int test_create_tensor() {
   int shape[] = {2, 2};
  Tensor* t = create_tensor(shape, 2, 1);

    // Initialize data
    t->data[0] = 1; t->data[1] = 2; t->data[2] = 3; t->data[3] = 4;

    // Assert
    assert(t->data[0] == 1);
    assert(t->data[1] == 2);
    assert(t->data[2] == 3);
    assert(t->data[3] == 4);

    free_tensor(t);
    return 0;
}


int main() {
    test_tensor();
    test_create_tensor();

    return 0; // Return success if all tests pass
}
