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

void LinkList::InsertAtEnd(int data)
{
  node *newNode = new node;
  node *one = new node;
  node *two = new node;
  node *temp = new node;

  newNode->data = data;
  one->data = 9;
  two->data = 6;
  one->next = two;
  two->next = NULL;
  head = one;
  newNode->next = NULL;
  if (head == NULL)
  {
    newNode->next = NULL;
    head = newNode;
  }
  else
  {

    while (head != NULL)
    {
      head = head->next;
    }
    head->next = newNode;
    newNode->next = NULL;
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
  link.InsertAtEnd(7);
  link.display(link.getNode());
}

// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//   int data;
//   struct node *next;
// };

// void addLast(struct node **head, int val)
// {

//   node *newNode = new node;
//   newNode->data = val;
//   newNode->next = NULL;

//   if (*head == NULL)
//     *head = newNode;
//   else
//   {
//     struct node *lastNode = *head;

//     while (lastNode->next != NULL)
//     {
//       lastNode = lastNode->next;
//     }

//     lastNode->next = newNode;
//   }
// }

// void printList(struct node *head)
// {
//   struct node *temp = head;

//   while (temp != NULL)
//   {
//     printf("%d->", temp->data);
//     temp = temp->next;
//   }
// }

// int main()
// {
//   struct node *head = NULL;

//   addLast(&head, 10);
//   addLast(&head, 20);
//   addLast(&head, 30);

//   printList(head);

//   return 0;
// }