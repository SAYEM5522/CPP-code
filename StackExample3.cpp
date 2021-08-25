#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *next;
};
void fun1(Node *head)
{
  if (head == NULL)
    return;

  while (head != NULL)
  {
    cout << head->data;
    head = head->next;
  }
}
void PopFront(Node *head)
{
  head = head->next;
  while (head != NULL)
  {
    cout << head->data;
    head = head->next;
  }
}
Node *pushBack(Node *head, int key)
{
  Node *newNode = new Node();
  newNode->data = key;
  while (head != NULL)
  {
    head = head->next;
  }
  head = newNode;
  return head;
  // newNode->next = NULL;
}
int main()
{
  Node *head = new Node();
  Node *one = new Node();
  Node *two = new Node();
  Node *three = new Node();
  head = NULL;
  one->data = 1;
  two->data = 2;
  three->data = 3;
  one->next = two;
  two->next = three;
  // three->next = NULL;
  head = one;
  fun1(head);
  cout << endl;
  PopFront(head);
  cout << endl;

  pushBack(head, 4);
}