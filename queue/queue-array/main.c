#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}

void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 0;
    Q -> Rear = 0;
}

Queue CreateQueue(int MaxElements)
{
    Queue Q;
    Q = (Queue)malloc(sizeof(struct QueueRecord));
    MakeEmpty(Q);
    Q->Capacity = MaxElements;
    Q->a = (int*)malloc(sizeof(int) * MaxElements);
    return Q;
}

void Enqueue(Queue Q, int x)
{
    if (IsFull(Q))
    {
        printf("The Queue is full.\n");
    }
    else
    {
        Q->Size++;
        if (++Q->Front == Q->Capacity)
        {
            Q->Front = 0;
        }
        Q->a[Q->Front] = x;
    }
}

void Dequeue(Queue Q)
{
    if (IsEmpty(Q))
    {
        printf("The Queue is Empty already.\n");
    }
    else
    {
        Q->Size--;
        Q->Rear++;
    }
}

void traversal(Queue Q)
{
    int i, j = 1;
    for (i = 0; i < Q->Size; i++)
    {
        if (Q->Rear + j == Q->Capacity)
        {
            j = -Q->Rear;
        }
        printf("%d ", Q->a[Q->Rear + j]);
        j++;
    }
    printf("\n");
}

int main()
{
    Queue q0;
    q0 = CreateQueue(10);
    Enqueue(q0, 5);
    Enqueue(q0, 4);
    Enqueue(q0, 3);
    Enqueue(q0, 5);
    Enqueue(q0, 1);
    Dequeue(q0);
    Dequeue(q0);
    Dequeue(q0);
    Enqueue(q0, 1);
    Enqueue(q0, 2);
    Enqueue(q0, 3);
    Enqueue(q0, 8);
    Enqueue(q0, 6);
    Enqueue(q0, 9);
    Enqueue(q0, 7);
    Enqueue(q0, 15);
    Enqueue(q0, 20);
    Dequeue(q0);
    Enqueue(q0, 20);
    traversal(q0);
    printf("%d %d %d %d\n", q0->Size, q0->Front, q0->Rear, q0->Capacity);
    Dequeue(q0);
    Dequeue(q0);
    Dequeue(q0);
    Dequeue(q0);
    Dequeue(q0);
    Dequeue(q0);
    Dequeue(q0);
    Dequeue(q0);
    Dequeue(q0);
    Dequeue(q0);
    Dequeue(q0);
    Dequeue(q0);
    Dequeue(q0);
    Dequeue(q0);
    Dequeue(q0);
    Dequeue(q0);
    Dequeue(q0);
    return 0;
}
