#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.h"

int Height(Position P)
{
    if (P == NULL)
        return -1;
    else
        return P->height;
}

int Max(int x, int y)
{
    return x >= y ? x : y;
}

Position SingleRotateWithLeft(Position K2)
{
    Position K1;
    K1 = K2->left;
    K2->left = K1->right;
    K1->right = K2;
    K2->height = Max(Height(K2->left), Height(K2->right)) + 1;
    K1->height = Max(Height(K1->left), K2->height) + 1;
    return K1;
}
Position SingleRotateWithRight(Position K2)
{
    Position K1;
    K1 = K2->right;
    K2->right = K1->left;
    K1->left = K2;
    K2->height = Max(Height(K2->left), Height(K2->right)) + 1;
    K1->height = Max(Height(K1->right), K2->height) + 1;
    return K1;
}
Position DoubleRotateWithLeft(Position K3)
{
    K3->left = SingleRotateWithRight(K3->left);
    return SingleRotateWithLeft(K3);
}
Position DoubleRotateWithRight(Position K3)
{
    K3->right = SingleRotateWithLeft(K3->right);
    return SingleRotateWithRight(K3);
}

AVLTree Insert(AVLTree T, int x)
{
    if (T == NULL)
    {
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->value = x;
        T->height = 0;
        T->left = T->right = NULL;
    }
    else
    if (x < T->value)
    {
        T->left = Insert(T->left, x);
        if (Height(T->left) - Height(T->right) == 2)
        {
            if (x < T->left->value)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    }
    else
    if (x > T->value)
    {
        T->right = Insert(T->right, x);
        if (Height(T->right) - Height(T->left) == 2)
        {
            if (x > T->right->value)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }
    }
    T->height = Max(Height(T->left), Height(T->right)) + 1;
    return T;
}

void InorderTraversal(AVLTree T)
{
    if (T->left != NULL)
    {
        InorderTraversal(T->left);
        printf("%d ", T->value);
    }
    else
        printf("%d ", T->value);
    if (T->right != NULL)
    {
        InorderTraversal(T->right);
    }
}

int main()
{
    AVLTree AVL0 = NULL;
    AVL0 = Insert(AVL0, 2);
    AVL0 = Insert(AVL0, 4);
    AVL0 = Insert(AVL0, 8);
    AVL0 = Insert(AVL0, 5);
    AVL0 = Insert(AVL0, 9);
    AVL0 = Insert(AVL0, 4);
    AVL0 = Insert(AVL0, 6);
    AVL0 = Insert(AVL0, 3);
    InorderTraversal(AVL0);
    return 0;
}
