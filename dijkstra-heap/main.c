#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Heap.h"

#define Infinity 5000

struct InfoNodeRecord
{
    int distance;
    int path;
};
typedef struct InfoNodeRecord InfoNode;

List *Input(int *m, int *n, int *s)
{
    int i, f, t, w;
    FILE *fp;
    fp = fopen("input.txt", "r");
    fscanf(fp, "%d", m);
    fscanf(fp, "%d", n);
    fscanf(fp, "%d", s);
    List *Graph;
    Graph = (List*)malloc(sizeof(List) * (*m + 1));
    for (i = 0; i < *m + 1; i++)
        Graph[i] = InitializeList(Graph[i]);    //Graph用邻接表存储着图
    for (i = 0; i < *n; i++)
    {
        fscanf(fp, "%d", &f);
        fscanf(fp, "%d", &t);
        fscanf(fp, "%d", &w);
        Append(Graph[f], t, w);
    }
    fclose(fp);
    return Graph;
}

void Initialize(InfoNode *result, int m, int s)
{
    int i;
    for (i = 0; i < m + 1; i++)
    {
        result[i].distance = Infinity;
        result[i].path = -1;
    }
    result[s].distance = 0;                     //初始化，除了起始点的距离为0，其余均为Infinity
}


InfoNode *dijkstra(List *Graph, int m, int s)
{
    int j, v;
    ListNode *p;
    InfoNode *result;
    PriorityQueue H;
    H = InitializePQ(m);
    result = (InfoNode*)malloc(sizeof(InfoNode) * (m + 1));
    Initialize(result, m, s);
    HeapInsert(H, s, result[s].distance);
    for (j = 0; j < m; j++)
    {
        v = DeleteMin(H);
        p = Graph[v]->next;
        while (p != NULL)
        {
            if (result[v].distance + p->value < result[p->vertex].distance)
            {
                result[p->vertex].distance = result[v].distance + p->value;
                result[p->vertex].path = v;
                HeapInsert(H, p->vertex, p->value);
            }
            p = p->next;
        }
    }
    return result;
}

void PrintPath(InfoNode *result, int t)
{
    if (result[t].path != -1)
    {
        PrintPath(result, result[t].path);
        printf("->");
    }
    printf("%d", t);
}

int main()
{
    int m, n, s, i;
    List *Graph = NULL;
    InfoNode *result = NULL;
    Graph = Input(&m, &n, &s);
    result = dijkstra(Graph, m, s);
    for (i = 1; i < m + 1; i++)
        printf("%d: %d\n", i, result[i].distance);
    for (i = 1; i < m + 1; i++)
    {
        PrintPath(result, i);
        printf("\n");
    }
    return 0;
}
