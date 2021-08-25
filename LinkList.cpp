#include <iostream>
using namespace std;

struct node
{
  int data;
  node *next;
};
class LinkList
{
public:
  LinkList();
  node *head;
  void InsertAtBeginning(int);
  void InsertAtEnd(int);
  void display(node *head);
  ~LinkList();
  node *getNode()
  {
    return head;
  }
};

LinkList::LinkList()
{
  head = NULL;
}
void LinkList::InsertAtBeginning(int data)
{

  node *newNode = new node;
  node *one = new node;
  node *two = new node;

  newNode->data = data;
  one->data = 9;
  two->data = 6;
  one->next = two;
  two->next = NULL;
  head = one;

  if (head == NULL)
  {
    head = newNode;
    newNode->next = NULL;
  }
  else
  {
    newNode->next = head;
    head = newNode;
  }
}
void LinkList::InsertAtEnd(int data)
{
  node *newNode = new node;
  newNode->next = NULL;
  while (head != NULL)
  {
    cout << head->data;
    head = head->next;
  }
}
void LinkList::display(node *head)
{
  while (head != NULL)
  {
    cout << head->data;
    head = head->next;
  }
}

LinkList::~LinkList()
{
}
int main()
{
  LinkList link;
  link.InsertAtBeginning(0);
  link.display(link.getNode());
}
