#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

struct AVLNode;
typedef struct AVLNode *Position;
typedef struct AVLNode *AVLTree;

AVLTree MakeEmpty(AVLTree T);
AVLTree Insert(AVLTree T, int x);
AVLTree Delete(AVLTree T, int x);

#endif // AVLTREE_H_INCLUDED

struct AVLNode
{
    int value;
    AVLTree left;
    AVLTree right;
    int height;
};
