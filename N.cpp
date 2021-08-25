#include <iostream>

using namespace std;

long long MaxPairWiseProduct(int numbers[])
{

  int n = *(&numbers + 1) - numbers;
  int max_index1 = -1;
  for (int i = 0; i < n; i++)

  {
    if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
      max_index1 = i;
  }
  int max_index2 = -1;
  for (int j = 0; j < n; j++)
  {
    if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
    {
      max_index2 = j;
    }
  }
  return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

int main()
{
  int n;
  cin >> n;
  int *p = new int(n);
  for (int i = 0; i < n; i++)
  {
    cin >> p[i];
  }
  // int *p = numbers;

  long long result = MaxPairWiseProduct(p);
  cout << result << "\n";
  return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// long long MaxPairWiseProduct(const vector<int> &numbers)
// {

//   int n = numbers.size();
//   int max_index1 = -1;
//   for (int i = 0; i < n; i++)

//   {
//     if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
//       max_index1 = i;
//   }
//   int max_index2 = -1;
//   for (int j = 0; j < n; j++)
//   {
//     if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
//     {
//       max_index2 = j;
//     }
//   }
//   return ((long long)(numbers[max_index1])) * numbers[max_index2];
// }

// int main()
// {
//   int n;
//   cin >> n;
//   vector<int> numbers(n);
//   for (int i = 0; i < n; i++)
//   {
//     cin >> numbers[i];
//   }

//   long long result = MaxPairWiseProduct(numbers);
//   cout << result << "\n";
//   return 0;
// }