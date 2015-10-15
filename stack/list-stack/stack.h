#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef struct Node Node;

int IsEmpty(Stack S);
Stack CreateStack(int n);
void DisposeStack(Stack S);
void Push(Stack S, int x);
int Top(Stack S);
void Pop(Stack S);

#endif // STACK_H_INCLUDED

struct Node
{
    int Element;
    PtrToNode Next;
};
