#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int row, col;
  void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis)
  {
    if (i < 0 || i >= row || j < 0 || j >= col || vis[i][j] || grid[i][j] == 0)
    {
      return;
    }

    vis[i][j] = true;
    dfs(i + 1, j, grid, vis);
    dfs(i - 1, j, grid, vis);
    dfs(i, j + 1, grid, vis);
    dfs(i, j - 1, grid, vis);
  }

  int numberOfIsland(vector<vector<int>> &grid)
  {
    int island = 0;

    vector<vector<bool>> vis(row, vector<bool>(col));

    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {
        if (grid[i][j] == 1 && !vis[i][j])
        {
          dfs(i, j, grid, vis);
          island++;
        }
      }
    }

    return island;
  }

  int minDays(vector<vector<int>> &grid)
  {
    row = grid.size();
    col = grid[0].size();

    int island = numberOfIsland(grid);

    if (island == 0 || island > 1)
    {
      return 0;
    }
    else
    {
      for (int i = 0; i < row; i++)
      {
        for (int j = 0; j < col; j++)
        {
          if (grid[i][j] == 1)
          {
            grid[i][j] = 0; // make water
            island = numberOfIsland(grid);

            if (island > 1 || island == 0)
            {
              return 1;
            }
            grid[i][j] = 1; // reset again
          }
        }
      }
    }

    return 2;
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> grid{{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
  solution.minDays(grid);
  return 0;
}
