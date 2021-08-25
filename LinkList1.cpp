#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};
class LinkList1
{

public:
  LinkList1();
  ~LinkList1();
  void InsetAtEnd(node *head, int data);
  void Print(node *head);
};

LinkList1::LinkList1()
{
}
void LinkList1::InsetAtEnd(node *head, int data)
{
  node *newNode = new node;
  node *temp = new node;
  temp = head;
  newNode->data = data;
  newNode->next = NULL;
  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}
void LinkList1::Print(node *head)
{
  while (head != NULL)
  {
    cout << head->data;
    head = head->next;
  }
};
LinkList1::~LinkList1()
{
}
int main()
{
  node *head = new node;
  head = NULL;
  LinkList1 link;
  link.InsetAtEnd(head, 6);
  link.InsetAtEnd(head, 6);
  link.InsetAtEnd(head, 6);

  link.Print(head);
}
