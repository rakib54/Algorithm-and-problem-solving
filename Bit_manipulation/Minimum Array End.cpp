#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  long long minEnd(int n, int x)
  {
    long long curr = x + 1;
    long long result = x;

    for (int i = 1; i < n; i++)
    {
      // to find next greater minimum number
      long long next_number = curr | x;
      result = next_number;
      curr = next_number + 1;
    }

    return result;
  }
};

int main()
{
  Solution solution;
  solution.minEnd(3, 4);

  return 0;
}
