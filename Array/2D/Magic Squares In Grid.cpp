#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool isMagicGrid(int row, int col, vector<vector<int>> &grid)
  {
    unordered_set<int> st;
    // check uniqueness num and num 1 to 9
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        int num = grid[row + i][col + j];
        if (num < 1 || num > 9 || st.count(num))
        {
          return false;
        }
        else
        {
          st.insert(num);
        }
      }
    }

    int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2]; // sum of first row or any

    // check all row sum
    for (int i = 0; i < 3; i++)
    {

      // check row sum
      if (grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2] != sum)
      {
        return false;
      }
      // check col sum
      if (grid[row][col + i] + grid[row + 1][col + i] + grid[row + 2][col + i] != sum)
      {
        return false;
      }
    }
    // diagonal sum
    if (grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2] != sum)
    {
      return false;
    }

    // antidiagonal sum

    if (grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col] != sum)
    {
      return false;
    }

    return true;
  }

  int numMagicSquaresInside(vector<vector<int>> &grid)
  {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    for (int i = 0; i <= rows - 3; i++)
    {
      for (int j = 0; j <= cols - 3; j++)
      {
        if (isMagicGrid(i, j, grid))
        {
          count++;
        }
      }
    }

    return count;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> grid{{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};
  s.numMagicSquaresInside(grid);
  return 0;
}
