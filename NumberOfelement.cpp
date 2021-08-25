#include <bits/stdc++.h>
using namespace std;

// Creating a node
class Node
{
public:
  int value;
  Node *next;
  int Count(Node *);
  int c = 0;
};
int Node::Count(Node *head)
{

  if (head == NULL)
  {
    return c;
  }
  else
  {
    c++;
    Count(head->next);
  }
  return c;
}
int main()
{
  Node h;
  Node *head;
  Node *tail = NULL;
  Node *one = NULL;
  Node *two = NULL;
  Node *three = tail;

  one = new Node();
  two = new Node();
  three = new Node();

  one->value = 1;
  two->value = 2;
  three->value = 3;

  one->next = two;
  two->next = three;
  three->next = NULL;

  head = one;
  h.Count(head);
  cout << h.c;
  // while (head != NULL)
  // {
  //   printf("%d ", head->value);
  //   head = head->next;
  // }
}