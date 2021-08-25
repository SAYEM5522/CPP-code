#include <iostream>
using namespace std;
class Node
{
public:
  int key;
  int sum = 0;
  Node *left;
  Node *right;

  Node(int val)
  {
    key = val;
    left = right = NULL;
  }
};

int f1(Node *root, int &total)
{

  if (!root)
  {
    return total;
  }

  f1(root->left, total);
  if (root->right != NULL)
  {
    total = total + root->right->key;
  }
  f1(root->right, total);

  return total;
}
Node *insert(Node *root, int key)
{
  if (!root)
  {
    return new Node(key);
  }
  if (root->key <= key)
  {
    root->right = insert(root->right, key);
  }
  else
  {
    root->left = insert(root->left, key);
  }
  return root;
}
void inorder(Node *root)
{
  if (!root)
  {
    return;
  }
  inorder(root->left);
  cout << root->key << " ";
  inorder(root->right);
}
int main()
{
  Node *root = NULL;
  Node *temp = NULL;
  Node *root1 = insert(root, 10);
  insert(root1, 20);
  insert(root1, 30);
  insert(root1, 35);
  insert(root1, 28);
  int sum = 0;
  // cout << f1(root1, sum);
  cout << f1(root1, sum);

  // insert(root1, 8);
  // insert(root1, 9);
  // insert(root1, 6);

  // inorder(root1);
}