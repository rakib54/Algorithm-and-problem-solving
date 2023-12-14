#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();

    vector<int> row(n, 0);
    vector<int> col(m, 0);

    vector<vector<int>> res(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 1)
        {
          row[i] += grid[i][j];
          col[j] += grid[i][j];
        }
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        res[i][j] = (2 * row[i] - n) + (2 * col[j] - m);
      }
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> grid{{0, 1, 1}, {1, 0, 1}, {0, 0, 1}};
  s.onesMinusZeros(grid);
  return 0;
}
