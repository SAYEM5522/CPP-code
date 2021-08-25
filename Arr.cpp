#include <iostream>
using namespace std;
struct node
{
  int data;
  node *left, *right;
  node *Root(node *);
};
void printInorder(node *root)
{
  if (!root)
    return;
  printInorder(root->left);
  cout << root->data << " ";
  printInorder(root->right);
}
node *newNode(int data)
{
  node *newN = new node;
  newN->data = data;
  newN->left = newN->right = NULL;
  return newN;
}
node *constructSubBT(node *root, int arr[], int start, int end)
{
  node *n = new node();
  int arrSize = *(&arr + 1) - arr;
  if (start >= end)
    return NULL;
  int i;
  for (i = start; i < end; ++i)
    if (arr[i] > root->data)
      break;
  // left
  if (i > start)
  {
    root->left = newNode(arr[i - 1]);
    constructSubBT(n->Root(root->left), arr, start, i - 1);
  }
  // right
  if (i >= start)
  {
    root->right = newNode(arr[end - 1]);
    constructSubBT(n->Root(root->right), arr, i, end - 1);
  }
  return root;
}
node *node::Root(node *root)
{
  return root;
}

int main()
{
  int post[] = {1, 7, 5, 50, 40, 10};
  int size = sizeof(post) / sizeof(post[0]);
  node *root = newNode(post[size - 1]);
  node *root2 = constructSubBT(root, post, 0, size - 1);
  printf("Inorder traversal of the constructed tree: \n");
  printInorder(root2);
  return 0;
}

// #include <iostream>
// using namespace std;
// class BinarySTree
// {
// public:
//   int key;
//   BinarySTree *left, *right = NULL;

//   BinarySTree *root;

//   BinarySTree()
//   {
//     root = NULL;
//     left = right = NULL;
//   }
//   BinarySTree *Newnode(int data)
//   {
//     BinarySTree *root = new BinarySTree();
//     root->key = data;
//     root->left = root->right = NULL;
//     return root;
//   }
//   BinarySTree *Tree(int firstItem, int arr[], BinarySTree *root, int size, int lastItem)
//   {
//     BinarySTree *n = new BinarySTree();
//     if (firstItem >= lastItem)
//     {
//       return NULL;
//     }
//     if (!root)
//     {
//       root = Newnode(arr[size - 1]);
//     }
//     int i;
//     for (i = firstItem; i < lastItem; ++i)
//       if (arr[i] > root->key)
//         break;
//     if (i > firstItem)
//     {
//       root->left = Newnode(arr[i - 1]);
//       Tree(firstItem, arr, root->left, size, i - 1);
//     }
//     if (i >= firstItem)
//     {
//       root->right = Newnode(arr[lastItem - 1]);
//       Tree(i, arr, root->right, size, lastItem - 1);
//     }
//     return root;
//   }

//   void inorder(BinarySTree *root)
//   {
//     if (!root)
//     {
//       return;
//     }
//     inorder(root->left);
//     cout << root->key << " ";
//     inorder(root->right);
//   }
// };

// int main()
// {
//   cout << "Enter the size of the Array: ";
//   int size;
//   cin >> size;

//   int array[size];
//   cout << "Enter The Elements of Array:";
//   for (int i = 0; i < size; i++)
//   {
//     cin >> array[i];
//   }
//   BinarySTree tree;
//   BinarySTree *root = tree.Tree(0, array, tree.root, size, size - 1);
//   cout << "Inorder traversal : ";
//   tree.inorder(root);
//   return 0;
// }