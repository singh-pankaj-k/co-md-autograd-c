//
// Created by Pankaj Priscilla on 2025-01-11.
//

#ifndef TENSOR_H
#define TENSOR_H

// Forward declaration of Tensor
struct Tensor;

// Backward function type
typedef void (*BackwardFunc)(struct Tensor*);

// Tensor structure
typedef struct Tensor {
    float* data;        // Data storage
    float* grad;        // Gradient storage
    int* shape;         // Shape of the tensor
    int* strides;       // Strides for each dimension
    int ndim;           // Number of dimensions
    int size;           // Total number of elements

    // Autograd components
    struct Tensor* parent1;   // First parent in the computational graph
    struct Tensor* parent2;   // Second parent in the computational graph
    BackwardFunc backward;    // Backward function for this tensor
    int requires_grad;        // Whether to track gradients
} Tensor;

// Initialize tensor
Tensor* create_tensor(int* shape, int ndim, int requires_grad);

// Free tensor memory
void free_tensor(Tensor* tensor);

#endif //TENSOR_H
