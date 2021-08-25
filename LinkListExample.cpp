#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *next;
  int prev;
};
void fun2(struct Node *head)
{
  if (head == NULL)
    return;
  cout << head->data << " ";

  if (head->next != NULL)
    fun2(head->next->next);
  cout << head->data << " ";
}
void fun1(Node *head)
{
  if (head == NULL)
    return;

  fun1(head->next);
  cout << head->data << " ";
}
// void fun(struct Node* head_ref)
// {
//     Node* temp = NULL;
//     Node* current = head_ref;
//     while (current !=  NULL)
//     {
//         temp =current->prev;
//         current->prev = current->next;
//         current->next = temp;
//         current = current->prev;
//     }

//     if(temp != NULL )
//         head_ref = temp->prev;
// }

int main()
{
  Node *head = new Node();
  Node *one = new Node();
  Node *two = new Node();
  Node *three = new Node();
  head = NULL;
  // one->next = two;
  // two->next = three;
  // three->next = NULL;
  // one->data = 1;
  // two->data = 2;
  // three->data = 3;
  // head = one;
  // fun2(head);
  // cout << endl;
  // fun1(head);
  // fun(&head);
}