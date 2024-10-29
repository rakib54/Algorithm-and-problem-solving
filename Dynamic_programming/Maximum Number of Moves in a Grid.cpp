#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
  int m, n;
  vector<int> directions{-1, 0, 1};
  int dp[1001][1001];
  int dfs(int row, int col, vector<vector<int>> &grid)
  {
    int moves = 0;

    if (dp[row][col] != -1)
    {
      return dp[row][col];
    }

    for (int dir : directions)
    {
      int newRow = row + dir;
      int newCol = col + 1;

      if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[row][col] < grid[newRow][newCol])
      {
        moves = max(moves, 1 + dfs(newRow, newCol, grid));
      }
    }

    return dp[row][col] = moves;
  }
  int maxMoves(vector<vector<int>> &grid)
  {
    m = grid.size();    // row
    n = grid[0].size(); // col
    memset(dp, -1, sizeof(dp));
    int result = 0;

    for (int row = 0; row < m; row++)
    {
      result = max(result, dfs(row, 0, grid));
    }

    return result;
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> grid{{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}};

  solution.maxMoves(grid);
  return 0;
}
