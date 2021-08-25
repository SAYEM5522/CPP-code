#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int c = 0;
void showstack(stack<int> s)
{
  while (!s.empty())
  {
    cout << '\t' << q.front();
    q.pop();
  }
  cout << '\n';
}
int Count()
{

  if (q.empty())
  {
    return c;
  }
  else
  {
    q.pop();
    c++;
    Count();
  }
  return c;
}

int main()
{

  q.push(10);
  q.push(30);
  q.push(20);
  q.push(5);
  q.push(1);
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
