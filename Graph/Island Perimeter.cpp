#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int n, m;
  void solve(vector<vector<int>> &grid, int &ans, int i, int j)
  {
    if (i < 0 || i >= n || j >= m || j < 0 || grid[i][j] == 0)
    {
      ans++;
      return;
    }

    if (grid[i][j] == -1)
    {
      return;
    }
    grid[i][j] = -1;

    solve(grid, ans, i + 1, j);
    solve(grid, ans, i - 1, j);
    solve(grid, ans, i, j + 1);
    solve(grid, ans, i, j - 1);
  }
  int islandPerimeter(vector<vector<int>> &grid)
  {
    int ans = 0;
    n = grid.size();
    m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 1)
        {
          solve(grid, ans, i, j);
          return ans;
        }
      }
    }

    return -1;
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> grid{{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
  solution.islandPerimeter(grid);
  return 0;
}
