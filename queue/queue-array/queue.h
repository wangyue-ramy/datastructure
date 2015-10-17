#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
typedef struct QueueRecord *Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
int Front(Queue Q);
void Dequeue(Queue Q);
void Enqueue(Queue Q, int x);

#endif // QUEUE_H_INCLUDED


struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    int *a;
};
