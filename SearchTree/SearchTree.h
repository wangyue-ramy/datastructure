#ifndef SEARCHTREE_H_INCLUDED
#define SEARCHTREE_H_INCLUDED

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(SearchTree T, int x);
Position FindMax(SearchTree T);
Position FindMin(SearchTree T);
SearchTree Insert(SearchTree T, int x);
SearchTree Delete(SearchTree T, int x);
int Retrieve(Position P);

#endif // SEARCHTREE_H_INCLUDED

struct TreeNode
{
    int value;
    SearchTree left;
    SearchTree right;
};
