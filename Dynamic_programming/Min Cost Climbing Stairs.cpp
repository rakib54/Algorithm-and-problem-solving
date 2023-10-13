#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int n;
  int dp[1001][1000];
  int solve(int i, int j, vector<int> &cost)
  {
    if (i >= n || j >= n)
    {
      return 0;
    }
    if (dp[i][j] != -1)
    {
      return dp[i][j];
    }
    int start_with_zero = 0;
    int start_with_one = 0;
    start_with_zero = cost[i] + solve(i + 1, j, cost);
    start_with_zero = min(start_with_zero, cost[i] + solve(i + 2, j, cost));

    start_with_one = cost[j] + solve(i, j + 1, cost);
    start_with_one = min(start_with_one, cost[j] + solve(i, j + 2, cost));

    return dp[i][j] = min(start_with_zero, start_with_one);
  }
  int minCostClimbingStairs(vector<int> &cost)
  {
    n = cost.size();
    memset(dp, -1, sizeof(dp));
    return solve(0, 1, cost);
  }
};

int main()
{
  Solution solution;
  vector<int> nums{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  solution.minCostClimbingStairs(nums);

  return 0;
}
