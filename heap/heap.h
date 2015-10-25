#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialize(int MaxElements);
void MakeEmpty(PriorityQueue H);
void Insert(PriorityQueue H, int x);
int DeleteMin(PriorityQueue H);

struct HeapStruct
{
    int Capacity;
    int Size;
    int *Elements;
};


#endif // HEAP_H_INCLUDED
