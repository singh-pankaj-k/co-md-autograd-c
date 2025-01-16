//
// Created by Pankaj Priscilla on 2025-01-11.
//

#include <string.h>
#include <stdlib.h>
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