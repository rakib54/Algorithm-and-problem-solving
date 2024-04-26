#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int n;
  int dp[201][201];
  int solve(int col, int row, vector<vector<int>> &grid)
  {
    if (row == n - 1)
    {
      return grid[row][col];
    }
    if (dp[row][col] != -1)
    {
      return dp[row][col];
    }
    int ans = INT_MAX;

    for (int nextCol = 0; nextCol < n; nextCol++)
    {
      if (nextCol != col)
      {
        ans = min(ans, solve(nextCol, row + 1, grid));
      }
    }

    return dp[row][col] = grid[row][col] + ans;
  }
  int minFallingPathSum(vector<vector<int>> &grid)
  {
    n = grid.size();
    memset(dp, -1, sizeof(dp));
    int result = INT_MAX;
    for (int col = 0; col < n; col++)
    {
      result = min(result, solve(col, 0, grid));
    }

    return result;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> grid{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 21}};
  s.minFallingPathSum(grid);
  return 0;
}
