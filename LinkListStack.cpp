
#include <bits/stdc++.h>
using namespace std;

// Declare linked list node


struct Node
{
  int key;
  struct Node *next;
};

struct Node *top;

// Utility function to add an element
// data in the stack insert at the beginning
void push(int data)
{

  // Create new node temp and allocate memory
  struct Node *temp;
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
int isEmpty()
{
  return top == NULL;
}

// Utility function to return top element in a stack
int peek()
{

  // Check for empty stack
  if (!isEmpty())
    return top->key;
  else
    exit(1);
}

// Utility function to pop top
// element from the stack
void pop()
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
  Node *head = top;
  Node *smallest = head;
  Node *temp = head;
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

  if (smallest != head)
  {
    prev->next = smallest->next;
  }
  else
  {
    head = head->next;
  }

  return head;
}
// Function to print all the
// elements of the stack
void display()
{
  struct Node *temp;

  // Check for stack underflow
  if (top == NULL)
  {
    cout << "\nStack Underflow";
    exit(1);
  }
  else
  {
    temp = top;
    while (temp != NULL)
    {

      // Print node data
      cout << temp->key << "-> ";

      // Assign temp link to temp
      temp = temp->next;
    }
  }
}

// Driver Code
int main()
{

  // Push the elements of stack
  push(11);
  push(22);
  push(33);
  push(44);

  // Display stack elements
  display();

  // Print top element of stack
  cout << "\nTop element is "
       << peek() << endl;
removeSmallest(peek());
  return 0;
}

// This code is contributed by Striver
