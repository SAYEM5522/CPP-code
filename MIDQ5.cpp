#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
class Node
{
public:
  int key;
  Node *next;

  // Node(int key)
  // {
  //   this->key = key;
  //   this->next = NULL;
  // }
  ~Node() {}
};
class Stack
{
public:
  Node *top;
  Stack()
  {
    top = NULL;
  }
  void push(int data);
  void pop();
  int peek();
  void display();
  int isEmpty();
};
Node *head = NULL;

void printNodes(Node *current)
{
  current = head;
  while (current != NULL)
  {
    cout << current->key << " -> ";
    current = current->next;
  }
  cout << "NULL" << endl;
}
// Utility function to add an element
// data in the stack insert at the beginning
void Stack::push(int data)
{

  // Create new node temp and allocate memory
  Node *temp;
  temp = new Node();

  // Check if stack (heap) is full.
  // Then inserting an element would
  // lead to stack overflow
  if (!temp)
  {
    cout << "\nHeap Overflow";
    exit(1);
  }

  // Initialize data into temp data field
  temp->key = data;

  // Put top pointer reference into temp link
  temp->next = top;

  // Make temp as top of Stack
  top = temp;
}

// Utility function to check if
// the stack is empty or not
int Stack::isEmpty()
{
  return top == NULL;
}

// Utility function to return top element in a stack
int Stack::peek()
{

  // Check for empty stack
  if (!isEmpty())
    return top->key;
  else
    exit(1);
}

// Utility function to pop top
// element from the stack
void Stack::pop()
{
  struct Node *temp;

  // Check for stack underflow
  if (top == NULL)
  {
    cout << "\nStack Underflow" << endl;
    exit(1);
  }
  else
  {

    // Top assign into temp
    temp = top;

    // Assign second node to top
    top = top->next;

    // Destroy connection between
    // first and second
    temp->next = NULL;

    // Release memory of top node
    free(temp);
  }
}
Node *removeSmallest(Node *top)
{
  Node *smallest = top;
  Node *temp = top;
  Node *prev = NULL;

  while (temp != NULL)
  {
    if (temp->next != NULL && temp->next->key < smallest->key)
    {
      smallest = temp->next;
      prev = temp;
    }
    temp = temp->next;
  }

  if (smallest != top)
  {
    prev->next = smallest->next;
  }
  else
  {
    top = top->next;
  }

  return top;
}
int main()
{
  Node *firstNode = new Node();
  head = firstNode;
  Node *secondNode = new Node();
  firstNode->next = secondNode;
  Node *thirdNode = new Node();
  secondNode->next = thirdNode;
  // Stack s = new Stack();
  Stack s;
  // printNodes(head);
  s.push(10);
  s.push(20);
  s.push(15);
  firstNode->key = s.peek();
  s.pop();
  secondNode->key = s.peek();
  s.pop();
  thirdNode->key = s.peek();
  s.pop();
  removeSmallest(head);

  // removeSmallest(s.peek());

  printNodes(head);
}
