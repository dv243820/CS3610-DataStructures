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

    cout << "You need to handle this case, as it is possible in AVL deletion. " << endl;
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

    cout << "You need to handle this case, as it is possible in AVL deletion. " << endl;
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

  return;
}

AVLNode *AVLTree::getPred(AVLNode *node)
{

  cout << "Should implement this getPred() function in Part B. \n";
  return NULL;
}

void AVLTree::remove(int badValue)
{
  bool isShorter = false;
  remove(root, badValue, isShorter);
}

void AVLTree::remove(AVLNode *&root, int badValue, bool &isShorter)
{

  cout << "Need to implement this remove() function in Part B. \n";
  return;
}

int AVLTree::nodeHeight(AVLNode *node)
{
  // Get the height of the tree
  if (node == NULL) //BASE CASE!!!!!!! IF NOTHING, RETURN 0
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