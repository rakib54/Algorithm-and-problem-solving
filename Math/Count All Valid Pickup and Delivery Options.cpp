#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int MOD = 1e9 + 7;
  int countOrders(int n)
  {
    if (n == 1)
    {
      return 1;
    }

    ll result = 1;

    for (int i = 2; i <= n; i++)
    {
      ll spaces = (i - 1) * 2 + 1;
      ll currspaces = (spaces * (spaces + 1) / 2) % MOD;
      result = (result * currspaces) % MOD;
    }

    return result % MOD;
  }
};

int main()
{
  Solution solution;
  solution.countOrders(3);

  return 0;
}

// Combinatorics problems
