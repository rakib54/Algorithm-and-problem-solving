#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int n, m;

  int solve(vector<vector<int>> &grid, int i, int j)
  {
    if (i < 0 || i >= n || j >= m || j < 0 || grid[i][j] == 0)
    {
      return 0;
    }

    int currentGoldValue = grid[i][j];
    grid[i][j] = 0;
    int maxGold = 0;

    maxGold = max(maxGold, solve(grid, i - 1, j)); // top
    maxGold = max(maxGold, solve(grid, i + 1, j)); // bottom
    maxGold = max(maxGold, solve(grid, i, j - 1)); // left
    maxGold = max(maxGold, solve(grid, i, j + 1)); // right

    grid[i][j] = currentGoldValue; // undo

    return currentGoldValue + maxGold;
  }
  int getMaximumGold(vector<vector<int>> &grid)
  {
    n = grid.size();
    m = grid[0].size();
    int maxGold = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] != 0)
        {
          maxGold = max(maxGold, solve(grid, i, j));
        }
      }
    }
    return maxGold;
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> grid{{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
  solution.getMaximumGold(grid);

  return 0;
}
