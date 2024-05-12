#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int findMax(vector<vector<int>> &grid, int row, int col)
  {
    int maxVal = -1;
    for (int i = row; i < row + 3; i++)
    {
      for (int j = col; j < col + 3; j++)
      {
        maxVal = max(maxVal, grid[i][j]);
      }
    }
    return maxVal;
  }
  vector<vector<int>> largestLocal(vector<vector<int>> &grid)
  {
    int n = grid.size();
    vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2));

    for (int row = 0; row < n - 2; row++)
    {
      for (int col = 0; col < n - 2; col++)
      {
        maxLocal[row][col] = findMax(grid, row, col);
      }
    }

    return maxLocal;
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> grid{{9, 9, 8, 1}, {5, 6, 2, 6}, {8, 2, 6, 4}, {6, 2, 2, 2}};
  solution.largestLocal(grid);
  return 0;
}
