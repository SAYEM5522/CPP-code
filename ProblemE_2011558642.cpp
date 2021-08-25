#include <iostream>
using namespace std;
class BinarySTree
{
public:
  int data;
  BinarySTree *left, *right = NULL;

  BinarySTree *Newnode(int data)
  {
    BinarySTree *root = new BinarySTree();
    root->data = data;
    root->left = root->right = NULL;
    return root;
  }
  BinarySTree *Tree(int arr[], BinarySTree *root, int size, int first, int last)
  {

    if (first >= last)
    {
      return NULL;
    }
    if (!root)
    {
      root = Newnode(arr[size - 1]);
    }
    int i;
    for (i = first; i < last; ++i)
      if (arr[i] > root->data)
        break;
    if (i > first)
    {
      root->left = Newnode(arr[i - 1]);
      Tree(arr, Root(root->left), size, first, i - 1);
    }
    if (i >= first)
    {
      root->right = Newnode(arr[last - 1]);
      Tree(arr, Root(root->right), size, i, last - 1);
    }
    return root;
  }
  BinarySTree *Root(BinarySTree *root)
  {
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
  cout << "Enter the size of the Array: ";
  int size;
  cin >> size;

  int arr[size];
  cout << "Enter The Elements of Array:";
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
  BinarySTree bst;
  BinarySTree *root;
  BinarySTree *root1 = bst.Tree(arr, root, size, 0, size - 1);
  cout << "Inorder traversal : ";
  bst.inorder(root1);
  return 0;
}