//
// Created by Pankaj Priscilla on 2025-01-13.
//

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

#endif //VALUE_H
