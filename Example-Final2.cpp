#include <iostream>
using namespace std;

struct node
{
  int key;
  int count;
  node *left, *right = NULL;
};

node *Node(int item)
{
  node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  temp->count = 1;
  return temp;
}

void Iorder(node *root)
{
  if (root != NULL)
  {
    Iorder(root->left);
    printf("%d(%d) ", root->key, root->count);
    Iorder(root->right);
  }
}

node *insert(node *node, int key)
{

  if (node == NULL)
    return Node(key);

  if (key == node->key)
  {
    (node->count)++;
    return node;
  }

  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

node *MinNode(node *node)
{
  struct node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

node *delNode(node *root, int key)
{

  if (!root)
    return root;

  if (key < root->key)
    root->left = delNode(root->left, key);

  else if (key > root->key)
    root->right = delNode(root->right, key);

  else
  {
    if (root->count > 1)
    {
      (root->count)--;
      return root;
    }

    if (root->left == NULL)
    {
      struct node *temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == NULL)
    {
      struct node *temp = root->left;
      delete root;
      return temp;
    }

    struct node *temp = MinNode(root->right);

    root->key = temp->key;

    root->right = delNode(root->right, temp->key);
  }
  return root;
}

int main()
{
  struct node *root = NULL;
  for (int i = 0; i < 3; i++)
  {
    cout << endl
         << "choice any operation :" << endl;
    cout << "1.Insert:\n2.inorder:\n3.delete:" << endl;
    int input;
    cin >> input;
    switch (input)
    {
    case 1:

      root = insert(root, 12);
      root = insert(root, 10);
      root = insert(root, 20);
      root = insert(root, 9);
      root = insert(root, 11);
      root = insert(root, 10);
      root = insert(root, 12);
      root = insert(root, 12);

      break;
    case 2:
      cout << "Inorder traversal " << endl;
      Iorder(root);
      break;
    case 3:

      root = delNode(root, 20);
      cout << "\nInorder traversal " << endl;
    }
  }
}