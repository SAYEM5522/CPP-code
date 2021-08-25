#include <bits/stdc++.h>
using namespace std;
stack<char> s1;
stack<char> s2;
stack<char> s3;
char c;
void print(stack<char> s)
{
  while (!s.empty())
  {
    cout << s.top();
    s.pop();
  }
}

int main()
{

  s1.push('E');
  s1.push('D');
  s1.push('C');
  s1.push('B');
  s1.push('A');

  s2.push(s1.top());
  s1.pop();
  s2.push(s1.top());
  s1.pop();
  s3.push(s2.top());
  s2.pop();
  s2.push(s1.top());
  s1.pop();
  s2.push(s1.top());
  s1.pop();
  s3.push(s2.top());
  s2.pop();
  s1.push(s2.top());
  s2.pop();
  s3.push(s2.top());
  s2.pop();
  s3.push(s1.top());
  s1.pop();
  s3.push(s1.top());
  s1.pop();
  print(s3);

  return 0;
}
