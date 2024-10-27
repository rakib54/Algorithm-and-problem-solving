#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int n, m;
  int dp[301][301];
  int solve(int i, int j, vector<vector<int>> &matrix)
  {
    if (i >= n || j >= m)
    {
      return 0;
    }

    if (matrix[i][j] == 0)
    {
      return 0;
    }

    if (dp[i][j] != -1)
    {
      return dp[i][j];
    }

    int right = solve(i, j + 1, matrix);
    int diagonal = solve(i + 1, j + 1, matrix);
    int below = solve(i + 1, j, matrix);

    return dp[i][j] = 1 + min({right, diagonal, below});
  }
  int countSquares(vector<vector<int>> &matrix)
  {
    n = matrix.size();
    m = matrix[0].size();
    memset(dp, -1, sizeof(dp));
    int result = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (matrix[i][j] == 1)
        {
          result += solve(i, j, matrix);
        }
      }
    }

    return result;
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> matrix{{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
  solution.countSquares(matrix);

  return 0;
}
