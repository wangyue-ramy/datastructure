#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

struct HeapStructRecord;
struct HeapElementRecord;
typedef struct HeapStructRecord HeapStruct;
typedef struct HeapElementRecord HeapElement;
typedef HeapStruct *PriorityQueue;

struct HeapElementRecord
{
    int vertex;
    int distance;
};
struct HeapStructRecord
{
    int Capacity;
    int Size;
    HeapElement *Elements;
};

PriorityQueue InitializePQ(int MaxElements)
{
    PriorityQueue H;
    H = (PriorityQueue)malloc(sizeof(HeapStruct));
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements = (HeapElement*)malloc(sizeof(HeapElement) * MaxElements);
    H->Elements[0].distance = -1;
    return H;
}

void HeapInsert(PriorityQueue H, int vertex, int distance)
{
    int i;
    for (i = ++H->Size; H->Elements[i / 2].distance > distance; i = i / 2)
        H->Elements[i].distance = H->Elements[i / 2].distance;
    H->Elements[i].distance = distance;
    H->Elements[i].vertex = vertex;
}

int DeleteMin(PriorityQueue H)
{
    int i, child;
    int MinVertex = H->Elements[1].vertex;
    HeapElement LastElement;
    LastElement = H->Elements[H->Size--];
    for (i = 1; i * 2 <= H->Size; i = child)
    {
        child = i * 2;
        if (child != H->Size && H->Elements[child + 1].distance < H->Elements[child].distance)
            child++;
        if (LastElement.distance > H->Elements[child].distance)
            H->Elements[i] = H->Elements[child];
        else
            break;
    }
    H->Elements[i] = LastElement;
    return MinVertex;
}


#endif // HEAP_H_INCLUDED
