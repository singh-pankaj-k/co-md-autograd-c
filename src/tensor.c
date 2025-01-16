//
// Created by Pankaj Priscilla on 2025-01-11.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "tensor.h"

Tensor* create_tensor(int* shape, int ndim, int requires_grad) {

    Tensor* tensor = (Tensor*)malloc(sizeof(Tensor));
    tensor->ndim = ndim;
    tensor->shape = (int*)malloc(ndim * sizeof(int));
    tensor->strides = (int*)malloc(ndim * sizeof(int));
    memcpy(tensor->shape, shape, ndim * sizeof(int));

    tensor->size = 1;
    for (int i = ndim - 1; i >= 0; --i) {
        tensor->strides[i] = tensor->size;
        tensor->size *= shape[i];
    }

    tensor->data = (float*)malloc(tensor->size * sizeof(float));
    tensor->grad = requires_grad ? (float*)calloc(tensor->size, sizeof(float)) : NULL;
    tensor->requires_grad = requires_grad;
    tensor->parent1 = tensor->parent2 = NULL;
    tensor->backward = NULL;

    return tensor;
}

void free_tensor(Tensor* tensor) {
    free(tensor->data);
    if (tensor->grad) free(tensor->grad);
    free(tensor->shape);
    free(tensor->strides);
    free(tensor);
}

// Backward function for addition
void addition_backward(Tensor* self) {
    if (self->parent1 && self->parent1->requires_grad) {
        for (int i = 0; i < self->size; ++i) {
            self->parent1->grad[i] += self->grad[i];
        }
    }
    if (self->parent2 && self->parent2->requires_grad) {
        for (int i = 0; i < self->size; ++i) {
            self->parent2->grad[i] += self->grad[i];
        }
    }
}

// Add function with gradient tracking
Tensor* add(Tensor* a, Tensor* b) {
    if (a->ndim != b->ndim || a->size != b->size) {
        printf("Error: Tensor shapes do not match for addition.\n");
        return NULL;
    }

    Tensor* result = create_tensor(a->shape, a->ndim, a->requires_grad || b->requires_grad);
    for (int i = 0; i < a->size; ++i) {
        result->data[i] = a->data[i] + b->data[i];
    }

    if (result->requires_grad) {
        // Capture parents and assign the backward function
        result->parent1 = a;
        result->parent2 = b;
        result->backward = addition_backward;
    }

    return result;
}
