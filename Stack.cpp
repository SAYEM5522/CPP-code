#include <iostream>
using namespace std;
class BinarySTree
{
public:
  int key;
  BinarySTree *left = NULL;
  BinarySTree *right = NULL;
  BinarySTree *Newnode(int data)
  {
    BinarySTree *Node = new BinarySTree();
    Node->key = data;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
  }
  BinarySTree *ArraySearch(int arr[], int start, int last)
  {
    BinarySTree *node;
    if (start > last)
    {
      return NULL;
    }
    int middle = (start + last) / 2;

    if (!node)
    {
      node = Newnode(arr[middle]);
    }
    node = Newnode(arr[middle]);
    node->left = ArraySearch(arr, start, middle - 1);
    node->right = ArraySearch(arr, middle + 1, last);
    return node;
  }

  void preorder(BinarySTree *root)
  {
    if (!root)
    {
      return;
    }
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
  }
};

int main()
{
  cout << "Enter the size of the Array: ";
  int size;
  cin >> size;

  int arr[size];
  cout << "Enter The Array Elements :";
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }

  BinarySTree tree;
  int start = 0;
  BinarySTree *root = tree.ArraySearch(arr, start, size - 1);
  cout << "Inorer  Traversal : ";
  cout << endl;
  cout << "Preorder  Traversal : ";
  tree.preorder(root);
  return 0;
}