#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(Stack S, int x)
{
    Node *p;
    p = (Node*)malloc(sizeof(Node));
    p->Element = x;
    p->Next = S->Next;
    S->Next = p;
}

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

void pop(Stack S)
{
    if (IsEmpty(S))
    {
        printf("It's an empty stack.");
    }
    else
    {
        S->Next = S->Next->Next;
    }
}

Stack create(int n)
{
    Node *h;
    int i, t;
    h = (Node*)malloc(sizeof(Node));
    h->Element = -1;
    h->Next = NULL;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &t);
        push(h, t);
    }
    return h;
}

int top(Stack S)
{
    if (IsEmpty(S))
    {
        printf("It's an empty stack.\n");
        return 0;
    }
    else
    {
        return S->Next->Element;
    }
}

void traversal(Stack S)
{
    Node *p;
    p = S->Next;
    while (p != NULL)
    {
        printf("%d ", p->Element);
        p = p->Next;
    }
    printf("\n");
}

int main()
{
    int n;
    Stack stack0;
    scanf("%d", &n);
    stack0 = create(n);
    traversal(stack0);
    printf("%d\n", top(stack0));

    push(stack0, 8);
    traversal(stack0);
    printf("%d\n", top(stack0));

    pop(stack0);
    traversal(stack0);
    printf("%d\n", top(stack0));

    return 0;
}
