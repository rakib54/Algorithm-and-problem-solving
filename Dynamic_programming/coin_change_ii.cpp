#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dp[301][5001];
  int n;
  int solve(int i, int amount, vector<int> &coins)
  {
    if (amount == 0)
    {
      return 1;
    }
    if (i == n)
    {
      return 0;
    }
    if (dp[i][amount] != -1)
    {
      return dp[i][amount];
    }
    if (coins[i] > amount)
    {
      return solve(i + 1, amount, coins);
    }
    int take = solve(i, amount - coins[i], coins); //
    int skip = solve(i + 1, amount, coins);

    return dp[i][amount] = take + skip;
  }
  int change(int amount, vector<int> &coins)
  {
    n = coins.size();
    memset(dp, -1, sizeof(dp));
    return solve(0, amount, coins);
  }
};

int main()
{
  Solution s;
  vector<int> coins = {1, 2, 5};
  int amount = 5;
  s.change(amount, coins);

  return 0;
}