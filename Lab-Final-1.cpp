#include <iostream>
using namespace std;
int summation(int n)
{
  if (n == 1)
  {
    return n;
  }
  else
  {
    return n + summation(n - 1);
  }
}
int main()
{
  int number = 100;
  cout << "Total sum of the series is  :" << summation(number);
}
