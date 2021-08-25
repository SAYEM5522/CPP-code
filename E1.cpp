#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
  vector<int> marks;
  int sum = 0;
  int avg;
  int num;
  float standardDeviation;

  for (int a = 1; a <= 8; a++)
  {
    cin >> num;
    marks.push_back(num);
  }

  for (int i = 0; i < 8; i++)
  {
    sum = sum + marks[i];
  }
  avg = sum / 8;
  cout << "sum: " << sum << endl;
  cout << "Avg: " << avg << endl;
  for (int i = 0; i < 10; ++i)
  {
    standardDeviation += pow(marks[i] - avg, 2);
  }
  cout << "standardDeviation: " << sqrt(standardDeviation / 10);

  return 0;
}