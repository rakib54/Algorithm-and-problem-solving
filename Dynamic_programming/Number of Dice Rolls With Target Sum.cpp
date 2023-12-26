#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  const int MOD = 1e9 + 7;
  int dp[31][1001];
  int solve(int n, int k, int target)
  {
    if (target == 0 && n == 0)
    {
      return 1;
    }
    if (n == 0 || target <= 0)
    {
      return 0;
    }
    if (dp[n][target] != -1)
    {
      return dp[n][target];
    }
    int ways = 0;
    for (int i = 1; i <= k; i++)
    {
      ways = (ways + solve(n - 1, k, target - i)) % MOD;
    }

    return dp[n][target] = ways % MOD;
  }
  int numRollsToTarget(int n, int k, int target)
  {
    memset(dp, -1, sizeof(dp));
    return solve(n, k, target);
  }
};

int main()
{
  Solution s;
  s.numRollsToTarget(2, 6, 7);
  return 0;
}
