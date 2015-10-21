#include <stdio.h>
#include <stdlib.h>
#include "SearchTree.h"

SearchTree MakeEmpty(SearchTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return NULL;
}

Position Find(SearchTree T, int x)
{
    if (T == NULL)
        return NULL;
    if (x < T->value)
        return Find(T->left, x);
    else
    if (x > T->value)
        return Find(T->right, x);
    else
        return T;
}

Position FindMin(SearchTree T)
{
    if (T == NULL)
        return NULL;
    else
    if (T->left == NULL)
        return T;
    else
        return FindMin(T->left);
}

Position FindMax(SearchTree T)
{
    if (T != NULL)
        while (T->right != NULL)
            T = T->right;
    return T;
}

SearchTree Insert(SearchTree T, int x)
{
    if (T == NULL)
    {
        T = (SearchTree)malloc(sizeof(struct TreeNode));
        T->value = x;
        T->left = T->right = NULL;
    }
    else
    if (x < T->value)
        T->left = Insert(T->left, x);
    else
    if (x > T->value)
        T->right = Insert(T->right, x);

    return T;
}

SearchTree Delete(SearchTree T, int x)
{
    SearchTree Tmp;
    if (T == NULL)
        return NULL;
    else
    if (x < T->value)
        T->left = Delete(T->left, x);
    else
    if (x > T->value)
        T->right = Delete(T->right, x);
    else
    if (T->left && T->right)
    {
        Tmp = FindMin(T->right);
        T->value = Tmp->value;
        T->right = Delete(T->right, T->value);
    }
    else
    {
        Tmp = T;
        if (T->left == NULL)
            T = T->right;
        else
        if (T->right == NULL)
            T = T->left;
        free(Tmp);
    }
    return T;
}

void PreorderTraversal(SearchTree T)
{
    printf("%d ", T->value);
    if (T->left != NULL)
        PreorderTraversal(T->left);
    if (T->right != NULL)
        PreorderTraversal(T->right);
}

void InorderTraversal(SearchTree T)
{
    if (T->left != NULL)
    {
        InorderTraversal(T->left);
        printf("%d ", T->value);
    }
    else
        printf("%d ", T->value);
    if (T->right != NULL)
        InorderTraversal(T->right);
}

void PostorderTraversal(SearchTree T)
{
    if (T->right != NULL)
    {
        PostorderTraversal(T->right);
        printf("%d ", T->value);
    }
    else
        printf("%d ", T->value);
    if (T->left != NULL)
        PostorderTraversal(T->left);
}

int main()
{
    SearchTree tree0 = NULL;
    tree0 = Insert(tree0, 8);
    tree0 = Insert(tree0, 2);
    tree0 = Insert(tree0, 1);
    tree0 = Insert(tree0, 6);
    tree0 = Insert(tree0, 4);
    tree0 = Insert(tree0, 3);
    PreorderTraversal(tree0);
    printf("\n");
    InorderTraversal(tree0);
    printf("\n");
    PostorderTraversal(tree0);
    return 0;
}
