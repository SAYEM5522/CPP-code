#include <iostream>
using namespace std;

class Node
{
public:
  char key;
  Node *next;
  Node *prev;
};

class DoublyList
{
public:
  Node *head;
  Node *tail;

  DoublyList()
  {
    head = NULL;
    tail = NULL;
  }

  void Pop(char c)
  {
    Node *tmp = new Node;
    tmp->key = c;
    tmp->next = NULL;
    tmp->prev = NULL;

    if (head == NULL)
    {
      head = tmp;
      tail = tmp;
    }
    else
    {
      tail->next = tmp;
      tmp->prev = tail;
      tail = tmp;
    }
  }

  void printNodes()
  {
    Node *current = this->head;
    while (current != NULL)
    {
      cout << current->key << " -> ";
      current = current->next;
    }
    cout << "NULL" << endl;
  }

  void printNodesUlta()
  {
    Node *current = this->tail;
    while (current != NULL)
    {
      cout << current->key << " -> ";
      current = current->prev;
    }
    cout << "NULL" << endl;
  }

  Node *Head()
  {
    return this->head;
  }
};

//6

Node *removeAllVowels(Node *head)
{
  DoublyList item;

  Node *current = head;
  while (current != NULL)
  {
    char temp = current->key;
    if (temp != 'a' && temp != 'e' && temp != 'i' && temp != 'o' && temp != 'u' && temp != 'A' && temp != 'E' && temp != 'I' && temp != 'O' && temp != 'U')
    {
      item.Pop(temp);
    }
    current = current->next;
  }
  return item.Head();
}

void printNodes(Node *current)
{
  while (current != NULL)
  {
    cout << current->key << " -> ";
    current = current->next;
  }
  cout << "NULL" << endl;
}

int main()
{
  DoublyList DL1;
  DL1.Pop('a');
  DL1.Pop('b');
  DL1.Pop('d');
  DL1.Pop('c');
  DL1.Pop('e');
  //DL1.printNodesUlta();
  Node *tmp = removeAllVowels(DL1.Head());
  //cout << DL1.getHead()->c << endl;
  printNodes(tmp);
}