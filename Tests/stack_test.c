#include <stdio.h>
#include <assert.h>
#include "stack.h"

void test_stack_init(void)
{
    Stack s;
    StackStatus status = stack_init(&s);

    assert(status == STACK_OK);
    assert(s.top == -1);

    printf("test_stack_init PASSED\n");
}

void test_stack_push(vcd oid)
{
    Stack s;
    stack_init(&s);

    StackStatus status = stack_push(&s, 10);
    assert(status == STACK_OK);
    assert(s.top == 0);
    assert(s.data[0] == 10);

    printf("test_stack_push PASSED\n");
}

void test_stack_pop(void)
{
    Stack s;
    int32_t value;

    stack_init(&s);
    stack_push(&s, 20);

    StackStatus status = stack_pop(&s, &value);
    assert(status == STACK_OK);
    assert(value == 20);
    assert(s.top == -1);

    printf("test_stack_pop PASSED\n");
}

void test_stack_peek(void)
{
    Stack s;
    int32_t value;

    stack_init(&s);
    stack_push(&s, 30);

    StackStatus status = stack_peek(&s, &value);
    assert(status == STACK_OK);
    assert(value == 30);
    assert(s.top == 0);

    printf("test_stack_peek PASSED\n");
}

void test_stack_overflow(void)
{
    Stack s;
    stack_init(&s);

    for (int i = 0; i < STACK_MAX_SIZE; i++) {
        assert(stack_push(&s, i) == STACK_OK);
    }

    assert(stack_push(&s, 100) == STACK_FULL);

    printf("test_stack_overflow PASSED\n");
}

void test_stack_underflow(void)
{
    Stack s;
    int32_t value;

    stack_init(&s);
    assert(stack_pop(&s, &value) == STACK_EMPTY);

    printf("test_stack_underflow PASSED\n");
}

int main(void)
{
    test_stack_init();
    test_stack_push();
    test_stack_pop();
    test_stack_peek();
    test_stack_overflow();
    test_stack_underflow();

    printf("\nALL STACK TESTS PASSED\n");
    return 0;
}

