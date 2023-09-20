#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#define NONE -1
#define CAPACITY 10

struct stack {
    int capacity;
    int top;
    void** elements;
};

struct stack* stack_new(void) {
    struct stack* stack = malloc(sizeof(struct stack));
    stack->capacity = CAPACITY;
    stack->top = NONE;

    stack->elements = calloc(stack->capacity, sizeof(void*));
    return stack;
}

void stack_free(struct stack* stack) {
    free(stack->elements);
    free(stack);
}

int stack_empty(struct stack* stack) {
  return stack->top == NONE;
}

void* stack_top(struct stack* stack) {
    if (stack->top == NONE) {
        return NULL;
    }
    return stack->elements[stack->top];
}

void* stack_pop(struct stack* stack) {
    if (stack->top == NONE) {
        return NULL;
    }

    void* top_element = stack->elements[stack->top];
    stack->top -= 1;

    return top_element;
}

int stack_push(struct stack* stack, void* data) {
  if (stack->top >= stack->capacity) {
      return 1;
  }
  stack->top += 1;

  stack->elements[stack->top] = data;

  return 0;
}
