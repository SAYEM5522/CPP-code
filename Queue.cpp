#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
  int data;
  int count;
  Node *left;
  Node *right;
  Node(int key)
  {
    data = key;
    left = NULL;
    right = NULL;
    count++;
  }
};
class BST
{
public:
  Node *root;
  BST()
  {
    root = NULL;
  }
  Node *insert(Node *root, int key);
  Node *del(Node *root, int key);
  Node *findMin(Node *root);
  void inorder(Node *root);
};
Node *BST::insert(Node *root, int key)
{

  if (root == NULL)
  {
    return new Node(key);
  }
  if (key == root->data)
  {
    (root->count)++;
    return root;
  }
  if (root->data > key)
  {
    root->left = insert(root->left, key);
  }
  else
  {
    root->right = insert(root->right, key);
  }
  return root;
}

Node *BST::findMin(Node *root)
{
  if (!root)
  {
    return NULL;
  }
  while (root->left != NULL)
  {
    root = root->left;
  }
  return root;
}

Node *BST::del(struct Node *root, int key)
{
  if (root->count > 1)
  {
    (root->count)--;
    return root;
  }
  if (key > root->data)
    root->right = del(root->right, key);
  else if (key < root->data)
    root->left = del(root->left, key);
  else
  {
    if (root->left == NULL && root->right == NULL)
    {
      free(root);
    }
    else if (root->right == NULL)
    {
      Node *dell = root;
      root = root->left;
      free(dell);
    }
    else if (root->left == NULL)
    {
      Node *dell = root;
      root = root->right;
      free(dell);
    }

    else
    {
      Node *dell = findMin(root->right);
      root->data = dell->data;
      root->right = del(root->right, dell->data);
    }
  }
  return root;
}

void BST::inorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  inorder(root->left);
  cout << root->data << "("
       << root->count << ") ";
  inorder(root->right);
}
int main()
{
  BST tree;
  Node *root;
  Node *data;
  cout << endl;
  while (true)
  {
    cout << endl
         << "choice any option :" << endl;
    cout << "1.Insert operation:\n";

    cout << "2.delete operation:\n";
    cout << "3.findMin operation:\n";

    cout << "4.inorder operation:" << endl;
    int input;
    cin >> input;
    if (input == 1)
    {
      int n = 5;

      int array[n];
      cout << "Enter the Tree elements : ";

      for (int i = 0; i < n; i++)
      {
        cin >> array[i];
      }
      root = tree.insert(root, array[0]);
      for (int i = 1; i < n; i++)
      {
        tree.insert(root, array[i]);
      }
    }

    else if (input == 2)
    {

      cout << "Enter Deleted Node :";
      int Delete;
      cin >> Delete;
      data = tree.del(root, Delete);
    }
    else if (input == 3)
    {
      data = tree.findMin(root);
      cout << "Minimum  Node: " << data->data;
      ;
    }

    else if (input == 4)
    {
      cout << "Inorder Traversel: ";
      tree.inorder(root);
    }
  }
}