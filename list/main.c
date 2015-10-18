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

void PrintLots(List L, List P)
{
    int i = 0;
    Node *p1, *p2;
    p1 = L->Next;
    p2 = P->Next;
    while (p2 != NULL)
    {
        while (i != p2->Element && p1 != NULL)
        {
            i++;
            p1 = p1->Next;
        }
        if (p1 == NULL)
        {
            break;
        }
        printf("%d ", p1->Element);
        p2 = p2->Next;
    }
    printf("\n");
}

List intersect(List L, List P)
{
    Node *p1 = L->Next;
    Node *p2 = P->Next;
    Node *s, *p;
    Node *h = (Node*)malloc(sizeof(Node));
    h->Element = -1;
    h->Next = NULL;
    p = h;
    while (p1 != NULL && p2 != NULL)
    {
        while (p1->Element < p2->Element)
        {
            p1 = p1->Next;
            if (p1 == NULL)
            {
                return h;
            }
        }
        while (p2->Element < p1->Element)
        {
            p2 = p2->Next;
            if (p2 == NULL)
            {
                return h;
            }
        }
        s = (Node*)malloc(sizeof(Node));
        s->Element = p1->Element;
        s->Next = NULL;
        p->Next = s;
        p = p->Next;
        p1 = p1->Next;
        p2 = p2->Next;
    }
    return h;
}

List TakeUnion(List L, List P)
{
    Node *h, *p, *p1, *p2, *s;
    h = (Node*)malloc(sizeof(Node));
    h->Element = -1;
    h->Next = NULL;
    p = h;
    p1 = L->Next;
    p2 = P->Next;
    while (p1 != NULL || p2 != NULL)
    {
        if (p1 == NULL || p1->Element > p2->Element)
        {
            s = (Node*)malloc(sizeof(Node));
            s->Element = p2->Element;
            s->Next = NULL;
            p->Next = s;
            p = p->Next;
            p2 = p2->Next;
        }
        if (p2 == NULL || p1->Element <= p2->Element)
        {
            s = (Node*)malloc(sizeof(Node));
            s->Element = p1->Element;
            s->Next = NULL;
            p->Next = s;
            p = p->Next;
            if (p2 != NULL && p2->Element == p1->Element)
            {
                p2 = p2->Next;
            }
            p1 = p1->Next;
        }
    }
    return h;
}

int main()
{
    List L, P, IList, UList;
    int Ln, Pn;
    scanf("%d", &Ln);
    L = create(Ln);
    scanf("%d", &Pn);
    P = create(Pn);
    PrintLots(L, P);
    IList = intersect(L, P);
    traversal(IList);
    UList = TakeUnion(L, P);
    traversal(UList);
    return 0;
}
