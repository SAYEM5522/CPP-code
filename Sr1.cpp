#include <iostream>
using namespace std;
#include <math.h>
int main()
{
  int n, i;
  int sum = 0;
  printf("Enter the n i.e. max values of series: ");
  cin >> n;
  sum = pow(((n * (n + 1)) / 2), 2);
  printf("Sum of the series : ");
  for (i = 1; i <= n; i++)
  {
    if (i != n)
      printf("%d^3 + ", i);
    else
      printf("%d^3 = %d ", i, sum);
  }
  return 0;
}