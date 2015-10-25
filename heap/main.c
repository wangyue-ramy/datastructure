#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

PriorityQueue Initialize(int n)
{
    PriorityQueue H;
    H = (PriorityQueue)malloc(sizeof(struct HeapStruct));
    H->Capacity = n;
    H->Size = 0;
    H->Elements = (int*)malloc(sizeof(int) * (n + 1));
    H->Elements[0] = 0;
    return H;
}

void Insert(PriorityQueue H, int x)
{
    int i;
    for (i = ++H->Size; H->Elements[i / 2] > x; i /= 2)
        H->Elements[i] = H->Elements[i / 2];
    H->Elements[i] = x;
}

void PrintHeap(PriorityQueue H)
{
    int i;
    for (i = 1; i <= H->Size; i++)
        printf("%d ", H->Elements[i]);
    printf("\n");
}

int DeleteMin(PriorityQueue H)
{
    int i, Child;
    int MinElement = H->Elements[1],
        LastElement = H->Elements[H->Size--];
    for (i = 1; i * 2 <= H->Size; i = Child)
    {
        Child = i * 2;
        if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])
            Child++;
        if (LastElement > H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else
            break;
    }
    H->Elements[i] = LastElement;
    return MinElement;
}

int main()
{
    PriorityQueue H;
    H = Initialize(20);
    Insert(H, 65);
    Insert(H, 21);
    Insert(H, 16);
    Insert(H, 31);
    Insert(H, 24);
    Insert(H, 31);
    Insert(H, 26);
    Insert(H, 19);
    Insert(H, 32);
    Insert(H, 13);
    Insert(H, 68);
    printf("The heap is as below:\n");
    PrintHeap(H);
    printf("The min Element %d is Delete. Now the heap is as below:\n", DeleteMin(H));
    PrintHeap(H);
    return 0;
}
