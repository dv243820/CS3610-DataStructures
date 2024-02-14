#include <iostream>
#include "binary_tree.h"
#include <queue>
using namespace std;
template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
  return (root == NULL);
}
template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
  root = NULL;
}
template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
  inorder(root);
}
template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
  preorder(root);
}
template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
  postorder(root);
}
template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
  return height(root);
}
template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
  return nodeCount(root);
}
template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
  return leavesCount(root);
}
template <class elemType>
void binaryTreeType<elemType>::
    inorder(binaryTreeNode<elemType> *p) const
{
  if (p != NULL)
  {
    inorder(p->llink);
    cout << p->info << " ";
    inorder(p->rlink);
  }
}
template <class elemType>
void binaryTreeType<elemType>::
    preorder(binaryTreeNode<elemType> *p) const
{
  if (p != NULL)
  {
    cout << p->info << " ";
    preorder(p->llink);
    preorder(p->rlink);
  }
}
template <class elemType>
void binaryTreeType<elemType>::
    postorder(binaryTreeNode<elemType> *p) const
{
  if (p != NULL)
  {
    postorder(p->llink);
    postorder(p->rlink);
    cout << p->info << " ";
  }
}
template <class elemType>
int binaryTreeType<elemType>::
    height(binaryTreeNode<elemType> *p) const
{
  if (p == NULL)
    return 0;
  else
    return 1 + max(height(p->llink), height(p->rlink));
}
template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
  if (x >= y)
    return x;
  else
    return y;
}

// DREW VANATTA FUNCTIONS
// CS3610 HW2 Q1

template <class elemType>
int binaryTreeType<elemType>::leafCount(binaryTreeNode<elemType> *node) // returns number of leaf nodes in tree RECURSIVELY
{
  if (node == NULL) // base case 1 - we reach NULL (THIS MEANS ONE SIDE WAS NULL)
  {
    return 0;
  }
  if (node->llink == NULL && node->rlink == NULL) // if both children null, we are at a leaf node
  {
    return 1;
  }
  else // we not at leaf, go down both sides
    return leafCount(node->llink) + leafCount(node->rlink);
}

template <class elemType>
int binaryTreeType<elemType>::nrLeafCount(binaryTreeNode<elemType> *node) // returns number of leaf nodes in tree NONRECURSIVELY
{
  int counter = 0;
  if (node == NULL)
  {
    return counter; // RETURN ZERO (counter still zero)
  }
  queue<binaryTreeNode<int> *> nodeq; // QUEUE OF NODES - so we can add to a to do order without recursion
  nodeq.push(node);                   // initialize root node into queue
  while (!nodeq.empty())              // WHILE QUEUE NOT EMPTY
  {
    binaryTreeNode<int> *tmp = nodeq.front();
    nodeq.pop();
    if (tmp->llink == NULL && tmp->rlink == NULL) // same logic as above in recursive
    {
      counter++;
    }
    if (tmp->llink != NULL) // IF THERE IS SOMETHING IN LEFT, ADD LEFT NODE TO QUEUE
    {
      nodeq.push(tmp->llink);
    }
    if (tmp->rlink != NULL) // SAME WITH RIGHT
    {
      nodeq.push(tmp->rlink);
    }
  }
  return counter;
}
