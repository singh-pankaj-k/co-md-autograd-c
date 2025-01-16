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

int test_add_tensor(){
// Create two tensors
    int shape[] = {2, 2};
    Tensor* a = create_tensor(shape, 2, 1);  // Requires gradient
    Tensor* b = create_tensor(shape, 2, 1);  // Requires gradient

    // Initialize data
    a->data[0] = 1; a->data[1] = 2; a->data[2] = 3; a->data[3] = 4;
    b->data[0] = 5; b->data[1] = 6; b->data[2] = 7; b->data[3] = 8;

    // Perform addition
    Tensor* c = add(a, b);

       // Assert
    assert(c->data[0] == 6);
    assert(c->data[1] == 8);
    assert(c->data[2] == 10);
    assert(c->data[3] == 12);

    free_tensor(a);
    free_tensor(b);
  return 0;
}

int test_add_backward_tensor(){
  int shape[] = {2, 2};

    // Create two tensors
    Tensor* a = create_tensor(shape, 2, 1);
    Tensor* b = create_tensor(shape, 2, 1);

    // Initialize data
    a->data[0] = 1; a->data[1] = 2; a->data[2] = 3; a->data[3] = 4;
    b->data[0] = 5; b->data[1] = 6; b->data[2] = 7; b->data[3] = 8;

    // Perform addition
    Tensor* c = add(a, b);

    // Initialize gradient of c
    c->grad[0] = 1; c->grad[1] = 3; c->grad[2] = 1; c->grad[3] = 0;

    // Perform backward pass
    if (c->backward) {
        c->backward(c);
    }

    printf("\n");
    printf("Gradients of c:\n");
    for (int i = 0; i < c->size; ++i) {
        printf("%.2f ", c->grad[i]);
    }
    printf("\n");

    printf("Gradients of a:\n");
    for (int i = 0; i < a->size; ++i) {
        printf("%.2f ", a->grad[i]);
    }
    printf("\n");

    printf("Gradients of b:\n");
    for (int i = 0; i < b->size; ++i) {
        printf("%.2f ", b->grad[i]);
    }
    printf("\n");

           // Assert
    assert(c->grad[0] == 1);
    assert(c->grad[1] == 3);
    assert(c->grad[2] == 1);
    assert(c->grad[3] == 0);

    // Free memory
    free_tensor(a);
    free_tensor(b);
    free_tensor(c);

    return 0;
}

int main() {
    test_tensor();
    test_create_tensor();
    test_add_tensor();
    test_add_backward_tensor();

    return 0; // Return success if all tests pass
}
