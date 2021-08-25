#include <bits/stdc++.h>
using namespace std;
stack<int> s;
int c = 0;
void showstack(stack<int> s)
{
  while (!s.empty())
  {
    cout << '\t' << s.top();
    s.pop();
  }
  cout << '\n';
}
int Count()
{

  if (s.empty())
  {
    return c;
  }
  else
  {

    s.pop();
    c++;
    Count();
  }
  return c;
}

int main()
{

  s.push(10);
  s.push(30);
  s.push(20);
  s.push(5);
  s.push(1);
  cout << Count();
  // cout << "The stack is : ";
  // showstack(s);

  // cout << "\ns.size() : " << s.size();
  // cout << "\ns.top() : " << s.top();

  // cout << "\ns.pop() : ";
  // s.pop();
  // showstack(s);

  return 0;
}
