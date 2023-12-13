#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int numSpecial(vector<vector<int>> &mat)
  {
    int n = mat.size();
    int m = mat[0].size();
    int count = 0;

    for (int row = 0; row < n; row++)
    {
      for (int col = 0; col < m; col++)
      {
        if (mat[row][col] == 0)
        {
          continue;
        }

        bool special = true;

        for (int r = 0; r < n; r++)
        { // check column
          if (r != row && mat[r][col] == 1)
          {
            special = false;
            break;
          }
        }
        for (int c = 0; c < m; c++)
        {
          if (c != col && mat[row][c] == 1)
          {
            special = false;
            break;
          }
        }
        if (special)
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
  vector<vector<int>> mat{{1, 0, 0}, {0, 1, 0}};
  s.numSpecial(mat);
  return 0;
}
