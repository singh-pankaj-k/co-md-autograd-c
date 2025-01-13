#include <assert.h>
#include <stdio.h>
#include "../src/value.h"

int test_value() {
  // Create Value
  Value v = {
    .val = 5.0,
    .grad = 0.0,
    .children = NULL,
    .n_children = 0,
    .backward = NULL};

  // Assert value
  assert(v.val == 5.0);
  assert(v.grad == 0.0);
  assert(v.children == NULL);
  assert(v.n_children == 0);
  assert(v.backward == NULL);

  return 0;
}

int test_make_value() {
  // Create Value
  Value* v = make_value(5.0);

  // Assert value
  assert(v->val == 5.0);
  assert(v->grad == 0.0);
  assert(v->children == NULL);
  assert(v->n_children == 0);
  assert(v->backward == NULL);

  return 0;
}

int main() {

  test_value();
  test_make_value();

  return 0;
}