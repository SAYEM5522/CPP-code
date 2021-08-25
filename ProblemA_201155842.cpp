#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int key)
  {
    data = key;
    left = NULL;
    right = NULL;
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
  if (!root)
  {
    return new Node(key);
  }
  if (root->data <= key)
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
      Node *dell = root;
      root = root->right;
      delete dell;
    }
    else if (root->right == NULL)
    {
      Node *dell = root;
      root = root->left;
      delete dell;
    }
    else
    {
      Node *dell = findMax(root->left);
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
  cout << root->data << " ";
  inorder(root->right);
}
int main()
{
  BST bst;
  Node *root;
  Node *temp;

  for (int i = 0; i < 7; i++)
  {
    cout << endl
         << "choice any operation :" << endl;
    cout << "1.Insert:\n2.search:\n3.delete:\n4.findMin:\n5.findMax:\n6.inorder:" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:

      int arr[5];
      cout << "Enter the Tree elements : ";

      for (int i = 0; i < 5; i++)
      {
        cin >> arr[i];
      }
      root = bst.insert(root, arr[0]);
      for (int i = 1; i < 5; i++)
      {
        bst.insert(root, arr[i]);
      }

      break;
    case 2:
      cout << "Enter Search Value:";
      int search;
      cin >> search;
      temp = bst.search(root, search);
      cout << endl;
      cout << "search Node:" << temp->data;
      break;
    case 3:
      cout << "Enter The  Value You Want To Delete :";
      int dell;
      cin >> dell;
      temp = bst.del(root, dell);
      cout << "Deleted Successfully";
      cout << endl;
      break;
    case 4:
      temp = bst.findMin(root);
      cout << "Minimum  Node: " << temp->data;
      break;

    case 5:
      temp = bst.findMax(root);
      cout << "Maximum Node: " << temp->data;
      cout << endl;
      break;

    case 6:
      cout << "Inorder Traversel: ";
      bst.inorder(root);
      break;

    default:
      cout << "Wrong choice ";
      break;
    }
  }
}