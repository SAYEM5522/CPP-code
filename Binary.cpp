#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

template <class ItemType>
struct TreeNode
{
  ItemType info;
  TreeNode *left;
  TreeNode *right;
};
enum OrderType
{
  PRE_ORDER,
  IN_ORDER,
  POST_ORDER
};
template <class ItemType>
class TreeType
{
public:
  TreeType();
  ~TreeType();
  void MakeEmpty();
  bool IsEmpty();
  bool IsFull();
  int LengthIs();
  void RetrieveItem(ItemType &item,
                    bool &found);
  void InsertItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetTree(OrderType order);
  void GetNextItem(ItemType &item,
                   OrderType order, bool &finished);
  void Print();

private:
  TreeNode<ItemType> *root;
  QueType<ItemType> preQue;
  QueType<ItemType> inQue;
  QueType<ItemType> postQue;
};
#endif // BINARYSEARCHTREE_H_INCLUDED

#include <iostream>
using namespace std;
template <class ItemType>
TreeType<ItemType>::TreeType()
{
  root = NULL;
}
template <class ItemType>
void Destroy(TreeNode<ItemType> *&tree)
{
  if (tree != NULL)
  {
    Destroy(tree->left);
    Destroy(tree->right);
    delete tree;
    tree = NULL;
  }
}
template <class ItemType>
TreeType<ItemType>::~TreeType()
{
  Destroy(root);
}
template <class ItemType>
void TreeType<ItemType>::MakeEmpty()
{
  Destroy(root);
}
template <class ItemType>
bool TreeType<ItemType>::IsEmpty()
{
  return root == NULL;
}
template <class ItemType>
bool TreeType<ItemType>::IsFull()
{
  TreeNode<ItemType> *location;
  try
  {
    location = new TreeNode<ItemType>;
    delete location;
    return false;
  }
  catch (bad_alloc &exception)
  {
    return true;
  }
}
template <class ItemType>
int CountNodes(TreeNode<ItemType> *tree)
{
  if (tree == NULL)
    return 0;
  else
    return CountNodes(tree->left) +
           CountNodes(tree->right) + 1;
}
template <class ItemType>
int TreeType<ItemType>::LengthIs()
{
  return CountNodes(root);
}
template <class ItemType>
void Retrieve(TreeNode<ItemType> *tree, ItemType &item, bool &found)
{
  if (tree == NULL)
    found = false;
  else if (item < tree->info)
    Retrieve(tree->left, item, found);
  else if (item > tree->info)
    Retrieve(tree->right, item, found);
  else
  {
    item = tree->info;
    found = true;
  }
}
template <class ItemType>
void TreeType<ItemType>::RetrieveItem(ItemType &item, bool &found)
{
  Retrieve(root, item, found);
}
template <class ItemType>
void Insert(TreeNode<ItemType> *&tree,
            ItemType item)
{
  if (tree == NULL)
  {
    tree = new TreeNode<ItemType>;
    tree->right = NULL;
    tree->left = NULL;
    tree->info = item;
  }
  else if (item < tree->info)
    Insert(tree->left, item);
  else
    Insert(tree->right, item);
}
template <class ItemType>
void TreeType<ItemType>::InsertItem(ItemType
                                        item)
{
  Insert(root, item);
}
template <class ItemType>
void Delete(TreeNode<ItemType> *&tree,
            ItemType item)
{
  if (item < tree->info)
    Delete(tree->left, item);
  else if (item > tree->info)
    Delete(tree->right, item);
  else
    DeleteNode(tree);
}
template <class ItemType>
void DeleteNode(TreeNode<ItemType> *&tree)
{
  ItemType data;
  TreeNode<ItemType> *tempPtr;
  tempPtr = tree;
  if (tree->left == NULL)
  {
    tree = tree->right;
    delete tempPtr;
  }
  else if (tree->right == NULL)
  {
    tree = tree->left;
    delete tempPtr;
  }
  else
  {
    GetPredecessor(tree->left, data);
    tree->info = data;
    Delete(tree->left, data);
  }
}
template <class ItemType>
void GetPredecessor(TreeNode<ItemType> *
                        tree,
                    ItemType &data)
{
  while (tree->right != NULL)
    tree = tree->right;
  data = tree->info;
}
template <class ItemType>
void TreeType<ItemType>::DeleteItem(ItemType
                                        item)
{
  Delete(root, item);
}
template <class ItemType>
void PreOrder(TreeNode<ItemType> *tree,
              QueType<ItemType> &Que)
{
  if (tree != NULL)
  {
    Que.Enqueue(tree->info);
    PreOrder(tree->left, Que);
    PreOrder(tree->right, Que);
  }
}
template <class ItemType>
void InOrder(TreeNode<ItemType> *tree,
             QueType<ItemType> &Que)
{
  if (tree != NULL)
  {
    InOrder(tree->left, Que);
    Que.Enqueue(tree->info);
    InOrder(tree->right, Que);
  }
}
template <class ItemType>
void PostOrder(TreeNode<ItemType> *tree,
               QueType<ItemType> &Que)
{
  if (tree != NULL)
  {
    PostOrder(tree->left, Que);
    PostOrder(tree->right, Que);
    Que.Enqueue(tree->info);
  }
}
template <class ItemType>
void TreeType<ItemType>::ResetTree(OrderType
                                       order)
{
  switch (order)
  {
  case PRE_ORDER:
    PreOrder(root, preQue);
    break;
  case IN_ORDER:
    InOrder(root, inQue);
    break;
  case POST_ORDER:
    PostOrder(root, postQue);
    break;
  }
}
template <class ItemType>
void TreeType<ItemType>::GetNextItem(ItemType &
                                         item,
                                     OrderType order, bool &finished)
{
  finished = false;
  switch (order)
  {
  case PRE_ORDER:
    preQue.Dequeue(item);
    if (preQue.IsEmpty())
      finished = true;
    break;
  case IN_ORDER:
    inQue.Dequeue(item);
    if (inQue.IsEmpty())
      finished = true;
    break;
  case POST_ORDER:
    postQue.Dequeue(item);
    if (postQue.IsEmpty())
      finished = true;
    break;
  }
}
template <class ItemType>
void PrintTree(TreeNode<ItemType> *tree)
{
  if (tree != NULL)
  {
    PrintTree(tree->left);
    cout << tree->info << " ";
    PrintTree(tree->right);
  }
}

#include <iostream>
using namespace std;
template <class ItemType>
QueType<ItemType>::QueType()
{
  front = NULL;
  rear = NULL;
}
template <class ItemType>
bool QueType<ItemType>::IsEmpty()
{
  return (front == NULL);
}
template <class ItemType>
bool QueType<ItemType>::IsFull()
{
  NodeType *location;
  try
  {
    location = new NodeType;
    delete location;
    return false;
  }
  catch (bad_alloc &exception)
  {
    return true;
  }
}

template <class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem)
{
  if (IsFull())
    throw FullQueue();
  else
  {
    NodeType *newNode;
    newNode = new NodeType;
    newNode->info = newItem;
    newNode->next = NULL;
    if (rear == NULL)
      front = newNode;
    else
      rear->next = newNode;
    rear = newNode;
  }
}
template <class ItemType>
void QueType<ItemType>::Dequeue(ItemType &item)
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
    NodeType *tempPtr;
    tempPtr = front;
    item = front->info;
    front = front->next;
    if (front == NULL)
      rear = NULL;
    delete tempPtr;
  }
}
template <class ItemType>
void QueType<ItemType>::MakeEmpty()
{
  NodeType *tempPtr;
  while (front != NULL)
  {
    tempPtr = front;
    front = front->next;
    delete tempPtr;
  }
  rear = NULL;
}
template <class ItemType>
QueType<ItemType>::~QueType()
{
  MakeEmpty();
}
#ifndef QUETYPE_H_INCLUDED
#define QUETYPE_H_INCLUDED
class FullQueue
{
};
class EmptyQueue
{
};
template <class ItemType>
class QueType
{
  struct NodeType
  {
    ItemType info;
    NodeType *next;
  };

public:
  QueType();
  ~QueType();
  void MakeEmpty();
  void Enqueue(ItemType);
  void Dequeue(ItemType &);
  bool IsEmpty();
  bool IsFull();

private:
  NodeType *front, *rear;
};
#endif // QUETYPE_H_INCLUDED

#include <iostream>

using namespace std;

int CheckIfTreeEmpty()
{
  TreeType<int> tree;
  QueType<int> q;
  if (tree.IsEmpty())
  {
    cout << "Tree is empty" << endl;
  }
  else
  {
    cout << "Tree is not empty" << endl;
  }
}
template <class ItemType>
void TreeType<ItemType>::Print()
{
  PrintTree(root);
}
int main()
{
  TreeType<int> tree;
  QueType<int> que1;
  bool var1;
  if (tree.IsEmpty())
  {
    cout << "Tree is empty" << endl;
  }
  else
  {
    cout << "Tree is not empty" << endl;
  }
  tree.InsertItem(4);
  tree.InsertItem(9);
  tree.InsertItem(2);
  tree.InsertItem(7);
  tree.InsertItem(3);
  tree.InsertItem(11);
  tree.InsertItem(17);
  tree.InsertItem(0);
  tree.InsertItem(5);
  tree.InsertItem(1);
  if (tree.IsEmpty())
  {
    cout << "Tree is empty" << endl;
  }
  else
  {
    cout << "Tree is not empty" << endl;
  }
  cout << tree.LengthIs() << endl;
  int var3 = 9;
  tree.RetrieveItem(var3, var1);
  if (var1 == true)
  {
    cout << "Item is found" << endl;
  }
  else
  {
    cout << "Item is not found" << endl;
  }
  int var4 = 13;
  tree.RetrieveItem(var4, var1);
  if (var1 == true)
  {
    cout << "Item is found" << endl;
  }
  else
  {
    cout << "Item is not found" << endl;
  }
  tree.Print();
  cout << endl;
  tree.ResetTree(PRE_ORDER);
  tree.Print();
  cout << endl;
  tree.ResetTree(POST_ORDER);
  tree.Print();
  cout << endl;
  tree.MakeEmpty();
  tree.InsertItem(11);
  tree.InsertItem(9);
  tree.InsertItem(4);
  tree.InsertItem(2);
  tree.InsertItem(7);
  tree.InsertItem(3);
  tree.InsertItem(17);
  tree.InsertItem(0);
  tree.InsertItem(5);
  tree.InsertItem(1);
}
