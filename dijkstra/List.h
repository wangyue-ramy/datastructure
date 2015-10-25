#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
struct ListNodeRecord;
typedef struct ListNodeRecord ListNode;
typedef ListNode *List;

List InitializeList(List L);
void Append(List L, int v, int w);

struct ListNodeRecord
{
    int vertex;
    int value;
    ListNode *next;
};

List InitializeList(List L)
{
    L = (ListNode*)malloc(sizeof(ListNode));
    L->value = -1;
    L->next = NULL;
    return L;
}

void Append(List L, int v, int w)
{
    ListNode *p = L, *s;
    while (p->next != NULL)
        p = p->next;
    s = (ListNode *)malloc(sizeof(ListNode));
    s->value = w;
    s->vertex = v;
    s->next = NULL;
    p->next = s;
}


#endif // LIST_H_INCLUDED
