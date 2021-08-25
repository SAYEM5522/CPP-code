#include <iostream>
using namespace std;
class ArrayList
{
public:
  int key;
  ArrayList *left;
  ArrayList *right;

  ArrayList()
  {

    left = right = NULL;
  }

  ArrayList *Newnode(int data)
  {
    ArrayList *root = new ArrayList();
    root->key = data;
    root->left = NULL;
    root->right = NULL;
    return root;
  }
  ArrayList *Tree(int first, int arr[], int last)
  {
    ArrayList *root;

    if (first > last)
    {
      return NULL;
    }
    int mid = (first + last) / 2;

    if (!root)
    {
      root = Newnode(arr[mid]);
    }
    root = Newnode(arr[mid]);
    root->left = Tree(first, arr, mid - 1);
    root->right = Tree(mid + 1, arr, last);
    return root;
  }

  void postorder(ArrayList *root)
  {
    if (!root)
    {
      return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
  }
};

int main()
{
  cout << "Enter the size of the Array: ";
  int n;
  cin >> n;

  int post[n];
  cout << "Enter The Elements of Array:";
  for (int i = 0; i < n; i++)
  {
    cin >> post[i];
  }

  ArrayList Array;
  int start = 0;
  ArrayList *root = Array.Tree(start, post, n - 1);

  cout << "Preorder  Traversal : ";
  Array.postorder(root);
  return 0;
}