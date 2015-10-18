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

int NotBracket(char ch)
{
    int i;
    char list[] = {'(', ')', '[', ']', '{', '}'};
    for (i = 0; i < 6; i++)
    {
        if (ch == list[i])
        {
            return 0;
        }
    }
    return 1;
}

int CheckBalance(char *s)
{
    int i = 1;
    Stack stack0;
    stack0 = create(0);
    if (!NotBracket(s[0]))
    {
        push(stack0, s[0]);
    }
    while (s[i] != '\0')
    {
        if (NotBracket(s[i]))
        {
            i++;
            continue;
        }
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            push(stack0, s[i]);
        } else {
            if ((s[i] == ')' && top(stack0) == '(') || (s[i] == ']' && top(stack0) == '[') || (s[i] == '}' && top(stack0) == '{'))
            {
                pop(stack0);
            } else {
                return 0;
            }
        }
        i++;
    }
    return IsEmpty(stack0);
}

int main()
{
    char s[10];
    scanf("%s", s);
    printf("%d", CheckBalance(s));
    return 0;
}
