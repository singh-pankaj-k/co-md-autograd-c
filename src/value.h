#include <stdio.h>
#include <stdlib.h>

#ifndef VALUE_H
#define VALUE_H

/**
 * @struct Value
 * // Creation of a Value node with a scalar value of 3.5
 * Value* my_value = (Value*)malloc(sizeof(Value));
 * my_value->val = 3.5;
 * my_value->grad = 0;  // Gradient is initialized to 0
 * my_value->children = NULL;  // No children initially
 * my_value->n_children = 0;  // No children count
 * my_value->backward = NULL;  // No backward function initially
 */
struct Value {
    float val;  // actual value
    float grad;  // gradient
    struct Value** children;  // children this value depends on
    int n_children;  // number of children
    void (*backward)(struct Value*);  // backward function to compute gradients
};

/**
* Instead of struct Value value_1 = {...} we can now do Value value_1 = {...}
*/
typedef struct Value Value;


/**
 * @brief Prints the attributes of a Value object.
 *
 * @example
 * Value* v = make_value(3.0);
 * print_value(v);  // Outputs: Value(val=5.00, grad=0.00)
 */
void print_value(Value* v) {
    printf("Value(val=%.2f, grad=%.2f)\n", v->val, v->grad);
}

/**
 * @brief Initialize a new Value object with a given float.
 *
 * This function allocates memory for a Value object and initializes its attributes.
 *
 * @param x The float value to initialize the Value object with.
 * @return A pointer to the newly created Value object.
 *
 * @example
 * Value* v = make_value(5.0);
 * print_value(v);  // Outputs: Value(val=5.00, grad=0.00)
 *
 * The allocated memory should be freed in the end.
 */
Value* make_value(float x) {
    Value* v = (Value*)malloc(sizeof(Value));
    v->val = x;
    v->grad = 0;
    v->children = NULL;
    v->n_children = 0;
    v->backward = NULL;
    return v;
}


#endif //VALUE_H
