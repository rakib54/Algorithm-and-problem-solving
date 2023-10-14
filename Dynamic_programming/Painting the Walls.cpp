#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int dp[501][501];
  int n;

  int solve(int curr, vector<int> &cost, vector<int> &time, int Walls_remaining)
  {
    if (Walls_remaining <= 0)
    {
      return 0;
    }

    if (curr == n)
    {
      return 1e9;
    }

    if (dp[curr][Walls_remaining] != -1)
    {
      return dp[curr][Walls_remaining];
    }
    int take = cost[curr] + solve(curr + 1, cost, time, Walls_remaining - time[curr] - 1);
    int dont_take = solve(curr + 1, cost, time, Walls_remaining);

    return dp[curr][Walls_remaining] = min(take, dont_take);
  }

  int paintWalls(vector<int> &cost, vector<int> &time)
  {
    memset(dp, -1, sizeof(dp));
    n = cost.size(); // no of walls
    return solve(0, cost, time, cost.size());
  }
};

int main()
{
  Solution s;
  vector<int> cost{2, 3, 4, 2};
  vector<int> time{1, 1, 1, 1};
  s.paintWalls(cost, time);

  return 0;
}
