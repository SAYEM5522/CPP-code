#include <iostream>
using namespace std;

const int MAX_ITEMS = 5;
class FullStack

{
};
class EmptyStack

{
};
template <class ItemType>
class StackType
{
public:
  StackType();
  bool IsFull();
  bool IsEmpty();
  void Push(ItemType);
  void Pop();
  ItemType Top();

private:
  int top;
  ItemType items[MAX_ITEMS];
};

template <class ItemType>
StackType<ItemType>::StackType()
{
  top = -1;
}
template <class ItemType>
bool StackType<ItemType>::IsEmpty()
{
  return (top == -1);
}
template <class ItemType>
bool StackType<ItemType>::IsFull()
{
  return (top == MAX_ITEMS - 1);
}
template <class ItemType>
void StackType<ItemType>::Push(ItemType newItem)
{
  if (IsFull())
    throw FullStack();
  top++;
  items[top] = newItem;
}
template <class ItemType>
void StackType<ItemType>::Pop()
{
  if (IsEmpty())
    throw EmptyStack();
  top--;
}
template <class ItemType>
ItemType StackType<ItemType>::Top()
{
  if (IsEmpty())
    throw EmptyStack();
  return items[top];
}
class FullQueue
{
};
class EmptyQueue
{
};
template <class ItemType>
class QueType
{
public:
  QueType();
  QueType(int max);
  ~QueType();
  void MakeEmpty();
  bool IsEmpty();
  bool IsFull();
  void Enqueue(ItemType);
  void Dequeue(ItemType &);

private:
  int front;
  int rear;
  ItemType *items;
  int maxQue;
};

template <class ItemType>
QueType<ItemType>::QueType(int max)
{
  maxQue = max + 1;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
}
template <class ItemType>
QueType<ItemType>::QueType()
{
  maxQue = 501;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
}
template <class ItemType>
QueType<ItemType>::~QueType()
{
  delete[] items;
}
template <class ItemType>
void QueType<ItemType>::MakeEmpty()
{
  front = maxQue - 1;
  rear = maxQue - 1;
}
template <class ItemType>
bool QueType<ItemType>::IsEmpty()
{
  return (rear == front);
}
template <class ItemType>
bool QueType<ItemType>::IsFull()
{
  return ((rear + 1) % maxQue == front);
}
template <class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem)
{
  if (IsFull())
    throw FullQueue();
  else
  {
    rear = (rear + 1) % maxQue;
    items[rear] = newItem;
  }
}
template <class ItemType>
void QueType<ItemType>::Dequeue(ItemType &item)
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
    front = (front + 1) % maxQue;
    item = items[front];
  }
}

int main()
{
  QueType<int> queue(4);
  StackType<int> stack;
  queue.Enqueue(66);
  queue.Enqueue(99);
  queue.Enqueue(44);
  queue.Enqueue(55);

  while (!queue.IsEmpty())
  {
    int item;
    queue.Dequeue(item);
    cout << item << " ";
    stack.Push(item);
  }
  cout << endl;
  while (!stack.IsEmpty())
  {
    cout << stack.Top() << " ";
    stack.Pop();
  }
}