#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  bool checkSubIsland(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2)
  {
    int n = grid2.size();
    int m = grid2[0].size();

    queue<pair<int, int>> q;
    q.push({i, j});
    grid2[i][j] = -1; // mark as visited
    bool result = true;

    while (!q.empty())
    {
      auto [x, y] = q.front();
      q.pop();

      if (grid1[x][y] != 1)
      {
        result = false;
      }

      for (vector<int> &dir : directions)
      {
        int new_x = x + dir[0];
        int new_y = y + dir[1];

        if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && grid2[new_x][new_y] == 1)
        {
          grid2[new_x][new_y] = -1;
          q.push({new_x, new_y});
        }
      }
    }
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
