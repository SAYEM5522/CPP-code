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
  Node *search(Node *root, int key);
  Node *del(Node *root, int key);
  Node *findMin(Node *root);
  Node *findMax(Node *root);
  void inorder(Node *root);
};
Node *BST::insert(Node *root, int key)
{

  if (root == NULL)
  {
    return new Node(key);
  }
  else if (key == root->data)
  {
    (root->count)++;
    return root;
  }
  else if (root->data <= key)
  {
    root->right = insert(root->right, key);
  }
  else
  {
    root->left = insert(root->left, key);
  }
  return root;
}
Node *BST::findMax(Node *root)
{
  if (root == NULL)
  {
    return NULL;
  }
  while (root->right != NULL)
  {
    root = root->right;
  }
  return root;
}
Node *BST::findMin(Node *root)
{
  if (root == NULL)
  {
    return NULL;
  }
  while (root->left != NULL)
  {
    root = root->left;
  }
  return root;
}
Node *BST::search(Node *root, int key)
{
  if (root != NULL && root->data == key)
  {
    return root;
  }
  else
  {
    if (key > root->data)
    {
      return search(root->right, key);
    }
    else
    {
      return search(root->left, key);
    }
  }
}

Node *BST::del(struct Node *root, int key)
{
  if (root == NULL)
    return NULL;
  if (root->count > 1)
  {
    (root->count)--;
    return root;
  }
  else if (key < root->data)
    root->left = del(root->left, key);
  else if (key > root->data)
    root->right = del(root->right, key);
  else
  {
    if (root->left == NULL && root->right == NULL)
    {
      delete root;
      root = NULL;
    }
    else if (root->left == NULL)
    {
      Node *temp = root;
      root = root->right;
      delete temp;
    }
    else if (root->right == NULL)
    {
      Node *temp = root;
      root = root->left;
      delete temp;
    }
    else
    {
      Node *temp = findMax(root->left);
      root->data = temp->data;
      root->right = del(root->right, temp->data);
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
  bool f = true;

  for (int i = 0; i < 7; i++)
  {

    cout << endl
         << "choice any option :" << endl;
    cout << "1.Insert operation:\n";

    cout << "2.delete operation:\n";
    cout << "3.findMin operation:\n";

    cout << "4.inorder operation:" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
      cout << "choice any option :" << endl;
      cout << "1.Insert operation:\n";

      cout << "2.delete operation:\n";
      cout << "3.findMin operation:\n";

      cout << "4.inorder operation:" << endl;
      int input;
      cin >> input;
    case 1:

      int array[7];
      cout << "Enter the Tree elements : ";

      for (int i = 0; i < 7; i++)
      {
        cin >> array[i];
      }
      root = tree.insert(root, array[0]);
      for (int i = 1; i < 7; i++)
      {
        tree.insert(root, array[i]);
      }
      break;

    case 2:

      cout << "Enter Deleted Node :";
      int Delete;
      cin >> Delete;
      data = tree.del(root, Delete);
      break;
    case 3:

      data = tree.findMin(root);
      cout << "Minimum  Node: " << data->data;
      break;

    case 4:

      cout << "Inorder Traversel: ";
      tree.inorder(root);
      break;
    }
  }
}