#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef Node *List;

struct node
{
    int value;
    Node *next;
};

List create(n)
{
    Node *h, *p, *s;
    int i;
    h = (Node*)malloc(sizeof(Node));
    h->value = -1;
    h->next = NULL;
    p = h;
    for (i = 0; i < n; i++)
    {
        s = (Node*)malloc(sizeof(Node));
        scanf("%d", &s->value);
        s->next = NULL;
        p->next = s;
        p = s;
    }
    return h;
}

void traversal(List L)
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

void reverse(List L)
{
    Node *p = L, *tmp;
    while (p->next != NULL && p->next->next != NULL)
    {
        tmp = (Node *)malloc(sizeof(Node));
        tmp = p->next;
        p->next = tmp->next;
        tmp->next = p->next->next;
        p->next->next = tmp;
        p = tmp;
    }
}


int main()
{
    int n;
    List list0;
    scanf("%d", &n);
    list0 = create(n);
    traversal(list0);
    reverse(list0);
    traversal(list0);
    return 0;
}
