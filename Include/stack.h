#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#define STACK_MAX_SIZE 50

//for error handling
typedef enum {
    STACK_OK = 0,
    STACK_FULL,
    STACK_EMPTY,
    STACK_NULL
} StackStatus;
//stack structure
typedef struct {
    int32_t data[STACK_MAX_SIZE];
    int32_t top;
} Stack;

//functions for stack operations
StackStatus stack_init(Stack *s);
StackStatus stack_push(Stack *s, int32_t value);
StackStatus stack_pop(Stack *s, int32_t *popped_value);
StackStatus stack_peek(const Stack *s, int32_t *top_value);
uint8_t stack_is_empty(const Stack *s);
uint8_t stack_is_full(const Stack *s);

#endif