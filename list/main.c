#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Node
{
    int Element;
    Position Next;
};

int IsEmpty(List L)
{
    Node *p;
    p = L->Next;
    return p == NULL;
}

void Insert(List L, int i, ElementType x)
{
    Node *p, *s;
    int j;
    j = 0;
    p = L;
    while (j != i)
    {
        j++;
        p = p->Next;
    }
    s = (Node*)malloc(sizeof(Node));
    s->Element = x;
    s->Next = p->Next;
    p->Next = s;
}

void DeleteByIndex(List L, int i)
{
    Node *p;
    int j = 0;
    p = L;
    while (j != i)
    {
        j++;
        p = p->Next;
    }
    p->Next = p->Next->Next;
}

void DeleteByValue(List L, int x)
{
    Node *p;
    while (L->Element == x)
    {
        L = L->Next;
    }
    p = L;
    while (p->Next != NULL)
    {
        if (p->Next->Element == x)
        {
            p->Next = p->Next->Next;
        } else {
            p = p->Next;
        }
    }
}

void traversal(List L)
{
    List curNode = L->Next;
    if (curNode == NULL)
    {
        printf("It's a empty List.\n");
    } else
    {
        while (curNode != NULL)
        {
            printf("%d ", curNode->Element);
            curNode = curNode->Next;
        }
        printf("\n");
    }
}

List create(int n)
{
    Node *h, *p, *s;
    int i;
    h = (Node*)malloc(sizeof(Node));
    h->Element = -1;
    h->Next = NULL;
    p = h;
    for (i = 0; i < n; i++)
    {
        s = (Node*)malloc(sizeof(Node));
        scanf("%d", &s->Element);
        s->Next = NULL;
        p->Next = s;
        p = s;
    }
    return h;
}

int GetLength(List L)
{
    Node *p;
    p = L->Next;
    int i = 0;
    while (p != NULL)
    {
        i++;
        p = p->Next;
    }
    return i;
}

int main()
{
    List list0;
    int n;
    printf("Create a new List:\n\n");

    printf("Type the length:");
    scanf("%d", &n);
    list0 = create(n);

    printf("\n");
    traversal(list0);

    printf("\n");
    printf("Is it empty?\n");
    printf("%d", IsEmpty(list0));

    printf("\n");
    Insert(list0, 4, 20);
    printf("Insert value 20 into position 4.\n");
    traversal(list0);

    printf("\n");
    DeleteByIndex(list0, 0);
    printf("Delete the node whose index is 0.\n");
    traversal(list0);

    printf("\n");
    DeleteByValue(list0, 4);
    printf("Delete all the node whose value is 4.\n");
    traversal(list0);

    printf("\n");
    n = GetLength(list0);
    printf("The length of the list: %d.\n", n);
    return 0;
}
