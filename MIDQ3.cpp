#include <iostream>
using namespace std;
class Node
{
public:
  char key;
  Node *next;
  bool isEqual(Node *, Node *);
  int d1 = 0;
  int d2 = 0;
};
bool Node::isEqual(Node *head1, Node *head2)
{
  bool f = true;
  while (head1 != NULL && head2 != NULL)
  {
    if (head1 != NULL && head2 == NULL)
    {
      return f = false;
    }
    else if (head1 == NULL && head2 != NULL)
    {
      return f = false;
    }
    else if (head1->key != head2->key)
    {
      return f = false;
    }
    head1 = head1->next;
    head2 = head2->next;
  }
  return f;
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
  // Node *seven = new Node();

  one->key = 'a';
  two->key = 'b';
  three->key = 'c';
  four->key = 'a';
  five->key = 'b';
  six->key = 'c';
  // seven->key = 'e';
  one->next = two;
  two->next = three;
  three->next = NULL;
  four->next = five;
  five->next = six;
  six->next = NULL;
  // seven->next = NULL;

  head1 = one;
  head2 = four;
  cout << obj.isEqual(head1, head2);
}