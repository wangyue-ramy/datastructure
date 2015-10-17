#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define ElementType int

struct Node;
typedef struct Node *PtrToNode;
typedef struct Node Node;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
Position Find(ElementType X, List L);
void DeleteByIndex(List L, int i);
void DeleteByValue(List L, int x);
Position FindPrevious(ElementType X, List L);
void Insert(List L, int i, ElementType x);

#endif // LIST_H_INCLUDED
