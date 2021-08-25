#include <iostream>
#include <math.h>
using namespace std;

const int MAX_ITEMS = 15;
class FullStack
// Exception class thrown
// by Push when stack is full.
{
};
class EmptyStack
// Exception class thrown
// by Pop and Top when stack is emtpy.
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

using namespace std;

using namespace std;

int EvaluateInToPs(string postfix);
int Value(int a, int b, char ope);
int precidence(char c)
{
  if (c == '^')
    return 3;
  else if (c == '*' || c == '/')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return 0;
}

string infixToPostfix(string s)
{
  StackType<char> st;
  st.Push(' ');
  char ch;
  string output;
  for (int i = 0; i < s.length(); i++)
  {
    ch = s[i];
    if ((s[i] >= 'a' && s[i] <= 'z') ||
        (s[i] >= 'A' && s[i] <= 'Z'))
    {
      output = output + s[i];
    }
    else if (ch >= '0' && ch <= '9')
    {
      output = output + ch;
    }

    else if (s[i] == '(')

      st.Push('(');

    else if (s[i] == ')')
    {
      while (st.Top() != ' ' && st.Top() != '(')
      {
        char c = st.Top();
        st.Pop();
        output += c;
      }
      if (st.Top() == '(')
      {
        char c = st.Top();
        st.Pop();
      }
    }

    else
    {
      while (st.Top() != ' ' && precidence(s[i]) <=
                                    precidence(st.Top()))
      {
        char c = st.Top();
        st.Pop();
        output += c;
      }
      st.Push(s[i]);
    }
  }

  while (st.Top() != ' ')
  {
    char c = st.Top();
    st.Pop();
    output += c;
  }
  cout << "Postfix Expression:" + output << endl;
  cout << output;
}

int EvaluateInToPs(string postfix)
{
  StackType<int> myStack;
  char ch;

  for (int i = 0; postfix[i]; i++)
  {
    ch = postfix[i];
    if (ch >= '0' && ch <= '9')
      myStack.Push(ch - '0');
    else
    {
      int a, b;
      a = myStack.Top();
      myStack.Pop();

      b = myStack.Top();
      myStack.Pop();

      myStack.Push(Value(a, b, ch));
    }
  }

  return myStack.Top();
}

int Value(int a, int b, char ope)
{
  if (ope == '+')
    return b + a;
  else if (ope == '-')
    return b - a;
  else if (ope == '*')
    return b * a;
  else if (ope == '/')
    return b / a;
  else if (ope == '^')
    return pow(b, a);
}

int main()
{
  string exp = "((((4*3)–8/(8/2)/2)*4*3)+(9–5)*3)";
  string post = infixToPostfix(exp);
  int result = EvaluateInToPs(post);
  cout << result;
  return 0;
}
