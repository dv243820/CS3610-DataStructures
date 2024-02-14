#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>

// Definition of the node
template <class elemType>
struct binaryTreeNode
{
  elemType info;
  binaryTreeNode<elemType> *llink;
  binaryTreeNode<elemType> *rlink;
};
// Definition of the class
template <class elemType>
class binaryTreeType
{
public:
  const binaryTreeType<elemType> &
  operator=(const binaryTreeType<elemType> &);
  // Overload the assignment operator.
  bool isEmpty() const;
  // Returns true if the binary tree is empty;
  // otherwise, returns false.
  void inorderTraversal() const;
  // Function to do an inorder traversal of the binary tree.
  void preorderTraversal() const;
  // Function to do a preorder traversal of the binary tree.
  void postorderTraversal() const;
  // Function to do a postorder traversal of the binary tree.
  int treeHeight() const;
  // Returns the height of the binary tree.
  int treeNodeCount() const;
  // Returns the number of nodes in the binary tree.
  int treeLeavesCount() const;
  // Returns the number of leaves in the binary tree.
  void destroyTree();
  // Deallocates the memory space occupied by the binary tree.
  // Postcondition: root = NULL;
  binaryTreeType(const binaryTreeType<elemType> &otherTree);
  // copy constructor
  binaryTreeType();
  // default constructor
  ~binaryTreeType();
  // destructor
  int leafCount(binaryTreeNode<elemType> *node); // ADDED HERE
  int nrLeafCount(binaryTreeNode<elemType> *node); // ADDED HERE

protected:
  binaryTreeNode<elemType> *root;

private:
  void copyTree(binaryTreeNode<elemType> *&copiedTreeRoot,
                binaryTreeNode<elemType> *otherTreeRoot);
  // Makes a copy of the binary tree to which
  // otherTreeRoot points. The pointer copiedTreeRoot
  // points to the root of the copied binary tree.
  void destroy(binaryTreeNode<elemType> *&p);
  // Function to destroy the binary tree to which p points.
  // Postcondition: p = NULL
  void inorder(binaryTreeNode<elemType> *p) const;
  // Function to do an inorder traversal of the binary
  // tree to which p points
  void preorder(binaryTreeNode<elemType> *p) const;
  // Function to do a preorder traversal of the binary
  // tree to which p points.
  void postorder(binaryTreeNode<elemType> *p) const;
  // Function to do a postorder traversal of the binary
  // tree to which p points.
  int height(binaryTreeNode<elemType> *p) const;
  // Function to return the height of the binary tree
  // to which p points.
  int max(int x, int y) const;
  // Returns the larger of x and y.
  int nodeCount(binaryTreeNode<elemType> *p) const;
  // Function to return the number of nodes in the binary
  // tree to which p points
  int leavesCount(binaryTreeNode<elemType> *p) const;
  // Function to return the number of leaves in the binary
  // tree to which p points
};

#endif