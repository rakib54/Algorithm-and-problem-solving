#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int n, m;
  void solve(vector<vector<char>> &grid, int i, int j)
  {
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0')
    {
      return;
    }

    grid[i][j] = '0'; // mark as visited

    solve(grid, i + 1, j);
    solve(grid, i - 1, j);
    solve(grid, i, j + 1);
    solve(grid, i, j - 1);
  }

  int numIslands(vector<vector<char>> &grid)
  {
    int countIsland = 0;
    n = grid.size();
    m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == '1')
        {
          solve(grid, i, j);
          countIsland++;
        }
      }
    }
    return countIsland;
  }
};

int main()
{
  vector<vector<char>> grid{{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
  Solution s;
  s.numIslands(grid);
  return 0;
}
