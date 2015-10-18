#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;
typedef Node *List;

struct node
{
    int value;
    Node *next;
};

List createList(n)
{
    int i;
    Node *h, *p, *s;
    h = (Node*)malloc(sizeof(Node));
    h->value = -1;
    h->next = NULL;
    p = h;
    for (i = 1; i <= n; i++)
    {
        s  = (Node*)malloc(sizeof(Node));
        s->value = i;
        s->next = NULL;
        p->next = s;
        p = s;
    }
    p->next = h;
    return h;
}

void traversal(List L)
{
    Node *p = L->next;
    while (p->value != -1)
    {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

/* -1 1 3 5 -1*/
void ClearOut(List L, int m)
{
    int i = 0;
    Node *p = L->next;
    Node *t = L;
    if (p->value == -1)
    {
        t = p;
        p = p->next;
    }
    while (i != m)
    {
        i++;
        t = p;
        p = p->next;
        if (p->value == -1)
        {
            t = p;
            p = p->next;
        }
    }
    t->next = p->next;
    free(p);
    if (t->next->next != t)
    {
        ClearOut(t, m);
    }
}

int main()
{
    List list0;
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    list0 = createList(n);
    ClearOut(list0, m);
    printf("%d\n", list0->next->value);
    return 0;
}
