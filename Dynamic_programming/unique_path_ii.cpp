#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int n, m;
  int dp[101][101];
  int solve(int i, int j, vector<vector<int>> &grid)
  {
    if (i >= n || j >= m || grid[i][j] == 1)
    {
      return 0;
    }
    if (i == n - 1 && j == m - 1)
    {
      return 1;
    }
    if (dp[i][j] != -1)
    {
      return dp[i][j];
    }

    int goright = solve(i + 1, j, grid);
    int godown = solve(i, j + 1, grid);

    return dp[i][j] = goright + godown;
  }
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {
    n = obstacleGrid.size();
    m = obstacleGrid[0].size();
    memset(dp, -1, sizeof(dp));

    return solve(0, 0, obstacleGrid);
  }
};
int main()
{
  Solution solution;
  vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  int res = solution.uniquePathsWithObstacles(obstacleGrid);
  cout << res << endl;
  return 0;
}