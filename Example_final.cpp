#include <iostream>
using namespace std;

class BinarySTree
{
public:
  int data;
  BinarySTree *left = NULL;
  BinarySTree *right = NULL;

  BinarySTree *Newnode(int val)
  {
    BinarySTree *node = new BinarySTree();
    node->data = val;

    node->left = NULL;
    node->right = NULL;

    return node;
  }
  BinarySTree *Tree(int firstItem, int arr[], int &index, int lastItem)
  {
    BinarySTree *root;
    if (firstItem > lastItem)
      return NULL;

    root = Newnode(arr[firstItem]);
    index += 1;

    if (firstItem == lastItem)
    {
      return root;
    }
    int i;
    for (i = firstItem; i <= lastItem; i++)
    {
      if (arr[i] > root->data)
        break;
    }
    root->left = Tree(index, arr, index, i - 1);
    root->right = Tree(i, arr, index, lastItem);

    return root;
  }
  void inorder(BinarySTree *root)
  {
    if (!root)
    {
      return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
};

int main()
{

  int arr[] = {10, 5, 1, 7, 40, 50};
  int size = sizeof(arr) / sizeof(arr[0]);

  int first = 0;
  BinarySTree tree;
  BinarySTree *root = tree.Tree(first, arr, first, size - 1);

  cout << "Inorder Traversal : ";
  tree.inorder(root);

  return 0;
}