#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int pivotInteger(int n)
  {
    if (n == 1)
    {
      return 1;
    }
    for (int i = 1; i <= n; i++)
    {
      int leftSum = i * (i + 1) / 2;
      int rightSum = n * (n + 1) / 2 - i * (i - 1) / 2;

      if (leftSum == rightSum)
      {
        return i;
      }
    }

    return -1;
  }
};

int main()
{
  Solution solution;
  solution.pivotInteger(8);
  return 0;
}
