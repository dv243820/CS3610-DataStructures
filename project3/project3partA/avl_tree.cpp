#include <iostream>
#include "avl_tree.h"
#include <stack>
using namespace std;

void AVLTree::insert(const int newValue)
{

  bool isTaller = false;
  AVLNode *newNode;
  newNode = new AVLNode(newValue);
  insertIntoAVL(root, newNode, isTaller);
}

void AVLTree::insertIntoAVL(AVLNode *&root, AVLNode *newNode, bool &isTaller)
{
  if (root == NULL)
  {
    root = newNode;
    isTaller = true;
  }
  else if (root->value == newNode->value)
  {
    cout << "Duplicate" << endl;
  }
  else if (root->value > newNode->value)
  {

    insertIntoAVL(root->left, newNode, isTaller);

    if (isTaller)
    {
      switch (root->bf)
      {
      case -1:
        balanceFromLeft(root);
        isTaller = false;
        break;

      case 0:
        root->bf = -1;
        isTaller = true;
        break;

      case 1:
        root->bf = 0;
        isTaller = false;
      }
    }
  }
  else
  {

    insertIntoAVL(root->right, newNode, isTaller);

    if (isTaller)
    {
      switch (root->bf)
      {
      case -1:
        root->bf = 0;
        isTaller = false;
        break;

      case 0:
        root->bf = 1;
        isTaller = true;
        break;

      case 1:
        balanceFromRight(root);
        isTaller = false;
      }
    }
  }
}

void AVLTree::rotateToLeft(AVLNode *&root)
{
  AVLNode *p;

  if (root == NULL)
    cout << "Error in the tree" << endl;
  else if (root->right == NULL)
    cout << "Error in the tree: No right subtree to rotate." << endl;
  else
  {
    p = root->right;
    root->right = p->left;
    p->left = root;
    root = p;
  }
}

void AVLTree::rotateToRight(AVLNode *&root)
{
  AVLNode *p;

  if (root == NULL)
    cout << "Error in the tree" << endl;
  else if (root->left == NULL)
    cout << "Error in the tree: No left subtree to rotate." << endl;
  else
  {
    p = root->left;
    root->left = p->right;
    p->right = root;
    root = p;
  }
}

void AVLTree::balanceFromLeft(AVLNode *&root)
{

  AVLNode *p;
  AVLNode *w;

  p = root->left;

  switch (p->bf)
  {
  case -1:
    root->bf = 0;
    p->bf = 0;
    rotateToRight(root);
    break;

  case 0: // You need to handle this case; possible in AVL deletion
  //logic from avl node deletion case 1.5 on the slides
    rotateToRight(root);
    p->bf = 1;
    p->right->bf = -1; //this is what was the root
    break;

  case 1:
    w = p->right;

    switch (w->bf)
    {
    case -1:
      root->bf = 1;
      p->bf = 0;
      break;
    case 0:
      root->bf = 0;
      p->bf = 0;
      break;
    case 1:
      root->bf = 0;
      p->bf = -1;
    }

    w->bf = 0;
    rotateToLeft(p);
    root->left = p;
    rotateToRight(root);
  }
}

void AVLTree::balanceFromRight(AVLNode *&root)
{
  AVLNode *p;
  AVLNode *w;

  p = root->right;
  switch (p->bf)
  {
  case -1:

    w = p->left;
    switch (w->bf)
    {
    case -1:
      root->bf = 0;
      p->bf = 1;
      break;
    case 0:
      root->bf = 0;
      p->bf = 0;
      break;
    case 1:
      root->bf = -1;
      p->bf = 0;
    }

    w->bf = 0;
    rotateToRight(p);
    root->right = p;
    rotateToLeft(root);
    break;

  case 0: // You need to handle this case; possible in AVL deletion

    rotateToLeft(root);
    p->bf = -1;
    p->left->bf = 1; //this is what was the root
    break;

  case 1:
    root->bf = 0;
    p->bf = 0;
    rotateToLeft(root);
  }
}

void AVLTree::print(char letter)
{
  if (root == NULL)
  {
    cout << "Empty" << endl;
  }
  else // tree isnt empty
  {
    stack<AVLNode *> stack; // both will need these
    AVLNode *current = root;
    if (letter == 'h') // HEIGHT OF NODES
    {

      while (current != NULL || stack.empty() == false) // current is not NULL or stack is nonempty
      {

        while (current != NULL) // real node, go left
        {
          stack.push(current);     // add to the stack
          current = current->left; // go left
        }

        current = stack.top(); // current back to before NULL
        stack.pop();           // pop it off stack

        // heres the "do shit" stage, as we're "visiting the node"
        cout << nodeHeight(current) << " ";

        current = current->right;
      }

    } // end of h

    if (letter == 'p') // STUFF INSIDE OF NODES
    {
      {

        while (current != NULL || stack.empty() == false) // current is not NULL or stack is nonempty
        {
          while (current != NULL) // real node, go left
          {
            stack.push(current); // add to the stack
            current = current->left;
          }

          current = stack.top();
          stack.pop();

          cout << current->value << " ";

          current = current->right;
        }
      }
    } // end of p
  }
  cout << endl;
  return;
}

AVLNode *AVLTree::getPred(AVLNode *node) // DONE IN PART B  --- COMPLETE
{
  if (!node) // if there's nothing
  {
    return NULL;
  }
  // to get predecessor in BST (so also AVL) you go left once, then repeatedly down right until you can't anymore
  if (node->left == NULL)
  {
    return NULL;
  }
  node = node->left;          // go left once
  while (node->right != NULL) // While we can go right
  {
    node = node->right;
  }
  return node;
}

void AVLTree::remove(int badValue)
{
  bool isShorter = false;
  remove(root, badValue, isShorter);
}

void AVLTree::remove(AVLNode *&root, int badValue, bool &isShorter)
{
  if (root == NULL)
  {
    return;
  }
  if (root->value > badValue) // bad value is less than the root, go left
  {
    remove(root->left, badValue, isShorter);
  }
  else if (root->value < badValue) // bad value is greater than value
  {
    remove(root->right, badValue, isShorter);
  }
  else if (root->value == badValue) // WE FOUND THE NODE TO REMOVE
  {
    if (root->left == NULL && root->right == NULL) // NO CHILDREN, LEAF NODE ----- CASE 1
    {

      root = NULL;
      delete root;
      isShorter = true;
    }
    if(root == nullptr){
      return;
    }
    if (root->left != NULL && root->right == NULL) // NODE HAS ONLY A LEFT CHILD ------ CASE 2
    {
      AVLNode *tmp = root->left; // create pointer to child that will be deleted after we copy it
      //
      // now copying EVERYTHING FORM LEFT into ROOT
      root->value = root->left->value;
      root->bf = root->left->bf;
      root->right = root->left->right;
      root->left = root->left->left;
      tmp = NULL;
      delete tmp; // removes the node that is floating off now
      isShorter = true;
    }
    if (root->right != NULL && root->left == NULL) // NODE HAS ONLY A RIGHT CHILD ------ CASE 3
    {
      AVLNode *tmp = root->right; // create pointer to child that will be deleted after we copy it
      //
      // now copying EVERYTHING FORM LEFT into ROOT
      root->value = root->right->value;
      root->bf = root->right->bf;
      root->left = root->right->left;
      root->right = root->right->right;
      delete tmp; // removes the node that is floating off now
      isShorter = true;
    }
    if (root->right != NULL && root->left != NULL) // NODE HAS TWO CHILDREN ----- CASE 4
    {
      AVLNode *pred = getPred(root);   // predecessor from getPred
      badValue = pred->value; // update the bad value
      root->value = pred->value;
      remove(root->left, getPred(root)->value, isShorter); //recursive call
      //I got all the logic and steps from the help pdf and textbook and for some reason the height
      //still seems to be off for this one and I cannot for the life of me figure out how to fix it
    }
  }
  if (isShorter)
  {

    switch (root->bf)
    {
    case -1:                      // CASE -1 - the left subtree was bigger than the right
      if (root->value < badValue) // BAD VALUE IS GREATER THAN ROOT VALUE, MEANING DELETED FROM RIGHT TREE
      {

        if (root->left->bf == 0)
        {
          rotateToRight(root);
          isShorter = false;
        }
        else if (root->left->bf == root->bf)
        {
          rotateToRight(root);
          root->left->bf = 0;
          root->bf = 0;
          isShorter = true;
        }
        else if (root->bf * -1 == root->left->bf)
        {
          rotateToRight(root->left);
          rotateToRight(root);
          root->bf = 0;
          isShorter = true;
        }
      }
      if (root->value > badValue) // OPPOSITE, IT WAS TO THE LEFT
      {
        root->bf = 0;
        isShorter = true;
      }

      break;

    case 0:                       // CASE 0 - left and right subtrees were the same height
      if (root->value > badValue) // the bad value is less than value, removed from left
      {
        root->bf = 1;
      }
      if (root->value < badValue)
      {
        root->bf = -1;
      }
      isShorter = false;
      break;

    case 1:                       // CASE 1 - right subtree was bigger than the left subtree
      if (root->value < badValue) // removed value is greater than root value, which means removed to the right
      {
        root->bf = 0;
        isShorter = true;
      }
      if (root->value > badValue) // removed value is less than node, removed from left
      {
        if (root->right->bf == 0)
        {
          rotateToLeft(root);
          isShorter = false;
        }
        else if (root->right->bf == root->bf)
        {
          rotateToLeft(root);
          root->right->bf = 0;
          root->bf = 0;
          isShorter = true;
        }
        else if (root->bf * -1 == root->right->bf) //balance factors are opposite of each other
        {
          balanceFromLeft(root->right);
          root->bf = 0;
          isShorter = true;
        }
      }
    }
  }
}

int AVLTree::nodeHeight(AVLNode *node)
{
  // Get the height of the tree
  if (node == NULL) // BASE CASE!!!!!!! IF NOTHING, RETURN 0
    return 0;
  else
  {
    // Find the height of both subtrees
    // and use the larger one
    int left_height = nodeHeight(node->left);
    int right_height = nodeHeight(node->right);
    if (left_height >= right_height)
    {
      return left_height + 1;
    }
    else
    {
      return right_height + 1;
    }
  }
}