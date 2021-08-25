#include <iostream>

#define size 5

using namespace std;

class Stack
{
public:
  int *array;
  int top;

  Stack()
  {
    array = new int[size];
    top = -1;
  }

  bool isFull()
  {
    return (top == size - 1);
  }

  bool isEmpty()
  {
    if (top == -1)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }

  int push(int data)
  { //Enter new data
    if (isFull())
    {
      cout << "Stack Overflow.";
    }

    top++;
    array[top] = data;
  }

  int peek()
  { //print the top value
    return array[top];
  }

  int pop()
  {
    if (isEmpty())
    {
      cout << "Stack underflow" << endl;
    }

    top--;
  }

  void printStack()
  {

    if (!isEmpty())
    {
      cout << array[top];
      pop();
      printStack();
    }
  }
};

int main()
{
  int data, temp;
  Stack object;

  object.push(1);
  object.push(2);
  object.push(3);
  object.push(4);
  object.printStack();
}