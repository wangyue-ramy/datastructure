#include <stdio.h>
#include <stdlib.h>

typedef struct item Item;
typedef Item *Polymonial;

struct item
{
    int coefficient;
    int power;
    Item *next;
};

Polymonial CreatePolymonial(n)
{
    int i;
    Item *h, *p, *s;
    h = (Polymonial)malloc(sizeof(Item));
    h->coefficient = 0;
    h->power = 0;
    h->next = NULL;
    p = h;
    for (i = 0; i < n; i++)
    {
        s = (Item*)malloc(sizeof(Item));
        scanf("%d", &s->coefficient);
        scanf("%d", &s->power);
        s->next = NULL;
        p->next = s;
        p = s;
    }
    return h;
}

Polymonial add(Polymonial L, Polymonial P)
{
    Polymonial h;
    Item *p1, *p2, *p, *s;
    p1 = L->next;
    p2 = P->next;
    h = (Polymonial)malloc(sizeof(Item));
    h->power = 0;
    h->coefficient = 0;
    h->next = NULL;
    p = h;
    while (p1 != NULL || p2 != NULL)
    {
        if (p2 == NULL || p1->power > p2->power)
        {
            s = (Polymonial)malloc(sizeof(Item));
            s->coefficient = p1->coefficient;
            s->power = p1->power;
            p1 = p1->next;
            s->next = NULL;
            p->next = s;
            p = s;
        }
        if (p1 == NULL || p1->power < p2->power)
        {
            s = (Polymonial)malloc(sizeof(Item));
            s->coefficient = p2->coefficient;
            s->power = p2->power;
            p2 = p2->next;
            s->next = NULL;
            p->next = s;
            p = s;
        }
        if (p1 != NULL && p2 != NULL && p1->power == p2->power)
        {
            s = (Polymonial)malloc(sizeof(Item));
            s->coefficient = p1->coefficient + p2->coefficient;
            s->power = p1->power;
            p1 = p1->next;
            p2 = p2->next;
            s->next = NULL;
            p->next = s;
            p = s;
        }
    }
    return h;
}

Polymonial multiply0(Polymonial L, Polymonial P)
{
    Polymonial h;
    int power;
    Item *p1, *p2, *p, *s, *t;
    h = (Polymonial)malloc(sizeof(Item));
    h->coefficient = 0;
    h->power = 0;
    h->next = NULL;
    p1 = L->next;
    p = h->next;
    while (p1 != NULL)
    {
        p2 = P->next;
        while (p2 != NULL)
        {
            power = p1->power + p2->power;
            t = h;
            p = t->next;
            while (p != NULL && p->power > power)
            {
                t = p;
                p = p->next;
            }
            if (p == NULL)
            {
                s = (Item*)malloc(sizeof(Item));
                s->power = power;
                s->coefficient = p1->coefficient * p2->coefficient;
                s->next = NULL;
                t->next = s;
            }
            else if (p->power == power)
            {
                p->coefficient = p->coefficient + p1->coefficient * p2->coefficient;
            }
            else if (p->power < power)
            {
                s = (Item*)malloc(sizeof(Item));
                s->power = power;
                s->coefficient = p1->coefficient * p2->coefficient;
                t->next = s;
                s->next = p;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return h;
}

/*Polymonial multiply1(Polymonial L, Polymonial P)
{
    Polymonial h;
    int power;
    Item *p1, *p2, *p, *s, *t, *t1, *t2;
    h = (Polymonial)malloc(sizeof(Item));
    h->coefficient = 0;
    h->power = 0;
    h->next = NULL;
    t1 = L->;
    p1 = t1->next;
    p = h->next;
    while (p1 != NULL)
    {
    }
}*/

void traversal(Polymonial P)
{
    Item *p = P->next;
    while (p != NULL)
    {
        printf("%d %d\n", p->coefficient, p->power);
        p = p->next;
    }
}

Polymonial power(Polymonial L, int n)
{
    if (n == 1)
    {
        return L;
    }
    if (n == 2)
    {
        return multiply0(L, L);
    }
    if (n > 2)
    {
        return multiply0(L, power(L, n - 1));
    }
}

int main()
{
    int m, n;
    Polymonial L, P, R;
    scanf("%d", &m);
    L = CreatePolymonial(m);
    /*scanf("%d", &n);
    P = CreatePolymonial(n);
    traversal(L);
    traversal(P);
    R = multiply0(L,P);*/
    R = power(L, 3);
    traversal(R);
    return 0;
}
