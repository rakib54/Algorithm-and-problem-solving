#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int solve(int n, vector<int> &dp)
  {
    if (n == 1 || n == 0)
    {
      return 1;
    }
    if (dp[n] != -1)
      return dp[n];
    int maximum = 0;

    for (int i = 1; i < n; i++)
    {
      int val = max(i * (n - i), i * solve(n - i, dp));
      maximum = max(maximum, val);
    }

    return dp[n] = maximum;
  }
  int integerBreak(int n)
  {
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
  }
};

int main()
{
  Solution s;
  s.integerBreak(10);
  return 0;
}
