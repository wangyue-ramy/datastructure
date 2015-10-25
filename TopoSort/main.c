#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "List.h"

int* Topsort(List *aList, int *Indegree, int m, int n)
{
    int *a = (int*)malloc(sizeof(int) * m);;
    Queue Q = NULL;
    Q = InitializeQueue(Q);
    ListNode *p;
    int i, v;
    for (i = 1; i < m; i++)
        if (Indegree[i] == 0)
            Enqueue(Q, i);
    i = 0;
    while (Q->Size > 0)
    {
        v = Dequeue(Q);
        a[i++] = v;
        p = aList[v]->next;
        while (p != NULL)
        {
            if (--Indegree[p->value] == 0)
                Enqueue(Q, p->value);
            p = p->next;
        }
    }
    return a;
}

void PrintArray(int *a, int len)
{
    int i;
    for (i = 0; i < len - 1; i++)
        printf("%d ", a[i]);
    printf("%d\n", a[len - 1]);
}

int main()
{
    int m, n, i, f, t, Indegree[50], *res;
    List aList[10];
    for (i = 1; i < 10; i++)
        aList[i] = InitializeList(aList[i]);
    scanf("%d", &m);
    scanf("%d", &n);
    for (i = 0; i < 50; i++)
        Indegree[i] = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &f);
        scanf("%d", &t);
        Append(aList[f], t);
        Indegree[t]++;
    }
    res = Topsort(aList, Indegree, m, n);

    PrintArray(res, m);
    return 0;
}
