#include "stack.h"
//empty return value
StackStatus stack_init(Stack *s)
{
    if (s == NULL) {
        return STACK_NULL;
    }

    s->top = -1;
    return STACK_OK;
}
//check empty
uint8_t stack_is_empty(const Stack *s)
{
    if (s == NULL) {
        return 1;
    }

    return (s->top == -1);
}
// check full
uint8_t stack_is_full(const Stack *s)
{
    if (s == NULL) {
        return 0;
    }

    return (s->top == (STACK_MAX_SIZE - 1));

}
//push function
StackStatus stack_push(Stack *s, int32_t value)
{
    if (s == NULL) {
        return STACK_NULL;
    }

    if (stack_is_full(s)) {
        return STACK_FULL;
    }

    s->top++;
    s->data[s->top] = value;

    return STACK_OK;
}
//pop function
StackStatus stack_pop(Stack *s, int32_t *popped_value)
{
    if (s == NULL || popped_value == NULL) {
        return STACK_NULL;
    }

    if (stack_is_empty(s)) {
        return STACK_EMPTY;
    }

    *popped_value = s->data[s->top];
    s->top--;

    return STACK_OK;
}
//peek function
StackStatus stack_peek(const Stack *s, int32_t *top_value)
{
    if (s == NULL || top_value == NULL) {
        return STACK_NULL;
    }

    if (stack_is_empty(s)) {
        return STACK_EMPTY;
    }

    *top_value = s->data[s->top];
    return STACK_OK;
}
