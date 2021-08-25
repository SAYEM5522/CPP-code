#include <bits/stdc++.h>
using namespace std;
stack<int> s1;
stack<int> s2;

char c;
void print(stack<int> s)
{
  while (!s.empty())
  {
    cout << s.top();
    s.pop();
  }
}

int main()
{
  s1.push(1);
  s2.push(s1.top());
  s1.pop();
  s1.push(5);
  s1.push(3);
  s2.push(s1.top());
  s1.pop();
  s2.push(s1.top());
  s1.pop();
  s1.push(2);
  s1.push(4);
  s2.push(s1.top());
  s1.pop();
  s2.push(s1.top());
  s1.pop();
  print(s2);

  return 0;
}
