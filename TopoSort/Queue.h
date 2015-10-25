#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

struct QueueNodeRecord;
struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef struct QueueNodeRecord QueueNode;
typedef QueueNode *Position;
struct QueueNodeRecord
{
    int Value;
    Position Next;
    Position Prev;
};

struct QueueRecord
{
    Position Rail;
    Position Head;
    int Size;
};

Queue InitializeQueue(Queue Q)
{
    Q = (Queue)malloc(sizeof(struct QueueRecord));
    Q->Rail = NULL;
    Q->Head = NULL;
    Q->Size = 0;
    return Q;
}
void Enqueue(Queue Q, int x)
{
    QueueNode *s;
    s = (QueueNode*)malloc(sizeof(QueueNode));
    s->Value = x;
    s->Next = NULL;
    s->Prev = NULL;
    if (Q->Size == 0)
    {
        Q->Rail = s;
        Q->Head = s;
    }
    else
    {
        Q->Rail->Prev = s;
        s->Next = Q->Rail;
        Q->Rail = s;
    }
    Q->Size++;
}
int Dequeue(Queue Q)
{
    int res;
    res = Q->Head->Value;
    if (Q->Size == 1)
    {
        Q->Head = NULL;
        Q->Rail = NULL;
    }
    else
    {
        Q->Head = Q->Head->Prev;
        Q->Head->Next = NULL;
    }
    Q->Size--;
    return res;
}
#endif // QUEUE_H_INCLUDED
