#include <bits/stdc++.h>
using namespace std;

// memoization
int solve(vector<int> &v, int i, int n, vector<vector<int>> &dp)
{
  if (n == 0)
    return 0;
  if (i < 0 || n < 0)
    return 1e9;
  if (dp[i][n] != -1)
    return dp[i][n];
  int not_take = 0;
  int take = 1 + solve(v, i, n - v[i], dp);
  not_take += solve(v, i - 1, n, dp);

  return dp[i][n] = min(take, not_take);
}

int numSquares(int n)
{
  vector<int> v;
  for (int i = 1; i * i <= n; i++)
  {
    v.push_back(i * i);
  }
  int size = v.size();
  vector<vector<int>> dp(v.size() + 1, vector<int>(n + 1, -1));
  return solve(v, size - 1, n, dp);
}

int main()
{
  cout << numSquares(13);
  return 0;
}

// tabulation solution

int numSquares(int n)
{
  vector<int> dp(n + 1, -1);
  dp[0] = 0;
  for (int target = 1; target <= n; target++)
  {
    int min_count = INT_MAX;

    for (int i = 1; i <= sqrt(target); i++)
    {
      int sq = i * i;
      int curr = 1 + dp[target - sq];
      min_count = min(min_count, curr);
    }
    dp[target] = min_count;
  }
  return dp[n];
}
