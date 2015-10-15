#include <stdio.h>
#include <stdlib.h>

#define MinStackSize 5

typedef struct stackStruct *stack;

struct stackStruct
{
    int top;
    int capacity;
    int *a;
};

void MakeEmpty(stack S)
{
    S->top = -1;
}

stack create(int max)
{
    stack S;
    S = malloc(sizeof(struct stackStruct));
    S->a = malloc(sizeof(int) * max);
    S->capacity = max;
    MakeEmpty(S);
    return S;
}

void push(stack S, int x)
{
    S->a[++S->top] = x;
}

void traversal(stack S)
{
    int i;
    for (i = S->top; i > -1; i--)
    {
        printf("%d ", S->a[i]);
    }
}

void pop(stack S)
{
    S->top--;
}

int main()
{
    stack stack0;
    stack0 = create(10);
    push(stack0, 5);
    push(stack0, 5);
    push(stack0, 4);
    traversal(stack0);
    pop(stack0);
    traversal(stack0);
    return 0;
}
