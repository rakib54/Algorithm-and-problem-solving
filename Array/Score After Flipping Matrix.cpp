#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int matrixScore(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
      if (grid[i][0] == 0)
      {
        // flip the row

        for (int j = 0; j < m; j++)
        {
          grid[i][j] = 1 - grid[i][j];
        }
      }
    }

    for (int j = 1; j < m; j++)
    { // traverse the column and countzero starts with 1 because 0th column already calculated
      int countZero = 0;

      for (int i = 0; i < n; i++)
      {
        if (grid[i][j] == 0)
        {
          countZero++;
        }
      }
      int countOnes = n - countZero;
      cout << n;

      if (countZero > countOnes)
      {
        // flip the column

        for (int i = 0; i < n; i++)
        {
          grid[i][j] = 1 - grid[i][j];
        }
      }
    }

    int score = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int val = grid[i][j] * pow(2, m - j - 1);
        score += val;
      }
    }

    return score;
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> grid{{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
  solution.matrixScore(grid);
  return 0;
}
