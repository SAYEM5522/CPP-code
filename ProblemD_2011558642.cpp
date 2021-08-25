#include <bits/stdc++.h>
using namespace std;

class BST
{
public:
  int data;
  BST *left;
  BST *right;
  BST *root;
  BST *AddRoot(int);
  void inorder(BST *root);
  BST *Tree(int, int arr[], int &, int);
  BST()
  {
    root = NULL;
    left = right = NULL;
  }
};

BST *BST::AddRoot(int val)
{
  BST *node = new BST();
  node->data = val;

  node->left = NULL;
  node->right = NULL;

  return node;
}
BST *BST::Tree(int first, int arr[], int &ItemIndex, int last)
{
  BST *node = new BST();
  if (first > last)
    return NULL;

  node->root = node->AddRoot(arr[first]);
  ItemIndex += 1;

  if (first == last)
  {
    return node->root;
  }
  int i;
  for (i = first; i <= last; i++)
  {
    if (arr[i] > node->root->data)
      break;
  }
  node->root->left = Tree(ItemIndex, arr, ItemIndex, i - 1);
  node->root->right = Tree(i, arr, ItemIndex, last);

  return node->root;
}
void BST::inorder(BST *root)
{
  if (!root)
  {
    return;
  }
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}
int main()
{

  int arr[] = {10, 5, 1, 7, 40, 50};
  int arrSize = *(&arr + 1) - arr;
  int firstIndex = 0;
  BST bst;
  BST *root = bst.Tree(firstIndex, arr, firstIndex, arrSize - 1);

  cout << "Inorder Traversal : ";
  bst.inorder(root);

  return 0;
}