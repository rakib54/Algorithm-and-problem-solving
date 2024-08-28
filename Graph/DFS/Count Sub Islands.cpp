#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool checkSubIsland(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2)
  {
    if (i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size())
    {
      return true;
    }

    if (grid2[i][j] == 0)
    { // only need land not water
      return true;
    }
    // mark as visited
    grid2[i][j] = 0;

    bool result = (grid1[i][j] == 1); // check in grid1 should be true

    result = result & checkSubIsland(i + 1, j, grid1, grid2);
    result = result & checkSubIsland(i - 1, j, grid1, grid2);
    result = result & checkSubIsland(i, j + 1, grid1, grid2);
    result = result & checkSubIsland(i, j - 1, grid1, grid2);

    return result;
  }
  int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
  {
    int n = grid2.size();
    int m = grid2[0].size();
    int subIsland = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid2[i][j] == 1 && checkSubIsland(i, j, grid1, grid2))
        {
          subIsland++;
        }
      }
    }

    return subIsland;
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> grid1{{1, 0, 1, 0, 1}, {1, 1, 1, 1, 1}, {0, 0, 0, 0, 0}, {1, 1, 1, 1, 1}, {1, 0, 1, 0, 1}};
  vector<vector<int>> grid2{{0, 0, 0, 0, 0}, {1, 1, 1, 1, 1}, {0, 1, 0, 1, 0}, {0, 1, 0, 1, 0}, {1, 0, 0, 0, 1}};

  solution.countSubIslands(grid1, grid2);
  return 0;
}
