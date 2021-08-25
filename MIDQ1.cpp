#include <iostream>
using namespace std;
class Node
{
public:
  int key;
  Node *next;
  int intersect(Node *, Node *);
};

int Node::intersect(Node *head1, Node *head2)
{
  int d1 = 0;
  int d2 = 0;
  int d;

  int count = 0;
  int t;
  while (head1 != NULL)
  {
    d1++;
    head1 = head1->next;
  }
  while (head2 != NULL)
  {
    d2++;
    head2 = head2->next;
  }
  if (d1 > d2)
  {
    d = d1 - d2;
  }
  else
  {
    d = d2 - d1;
  }
  // Node *current1 = head1;
  // Node *current2 = head2;

  for (int i = 0; i < d; i++)
  {
    if (head1 == NULL)
    {
      return -1;
    }
    head1 = head1->next;
  }
  while (head1 != NULL && head2 != NULL)
  {
    if (head1 == head2)
      return head1->key;

    head1 = head1->next;
    head2 = head2->next;
  }
}
int main()
{
  Node obj;
  Node *head1 = new Node();
  Node *head2 = new Node();
  Node *one = new Node();
  Node *two = new Node();
  Node *three = new Node();
  Node *four = new Node();
  Node *five = new Node();
  Node *six = new Node();
  // Node *N = new Node();
  one->key = 1;
  two->key = 2;
  three->key = 3;
  four->key = 4;
  five->key = 2;
  six->key = 3;
  // N->key = 4;
  one->next = two;
  two->next = three;
  three->next = NULL;
  // N->next = NULL;
  four->next = five;
  five->next = six;
  six->next = NULL;
  head1 = one;
  head2 = four;
  cout << obj.intersect(head1, head2);
}