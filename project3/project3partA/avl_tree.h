#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <iostream>

struct AVLNode {
  AVLNode(const int value) : value(value), left(NULL), right(NULL), bf(0) {}

  ~AVLNode() {
    delete left;
    delete right;
    left = right = NULL;
  }
  int value;
  int bf;
  AVLNode *left, *right;
};

class AVLTree {
public:
  AVLTree() : root(NULL) {}
  ~AVLTree() { 
    delete root;
  }
  
  void insert(const int newValue);
  void remove(int badValue);
  
  void print(char letter);
  
  AVLNode* getPred(AVLNode* node);
  
  int nodeHeight(AVLNode* node); //added to get node height
  
private:
  void insertIntoAVL(AVLNode* &root, AVLNode *newNode, bool& isTaller);
  
  void rotateToLeft(AVLNode* &root);
  void rotateToRight(AVLNode* &root);
  
  void balanceFromLeft(AVLNode* &root);
  void balanceFromRight(AVLNode* &root);
  
  void remove(AVLNode* &root, int badValue, bool& isShorter);
  
  AVLNode* root;
};

#endif

