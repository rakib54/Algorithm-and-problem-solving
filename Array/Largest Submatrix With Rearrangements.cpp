#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int largestSubmatrix(vector<vector<int>> &matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    int maxArea = 0;

    for (int row = 0; row < m; row++)
    {
      for (int col = 0; col < n; col++)
      {
        if (matrix[row][col] == 1 && row > 0)
        { // finding consecutive 1's
          matrix[row][col] += matrix[row - 1][col];
        }
      }

      vector<int> heights = matrix[row];

      sort(heights.begin(), heights.end(), greater<int>());

      for (int i = 0; i < n; i++)
      {
        int base = i + 1;
        int height = heights[i];
        maxArea = max(maxArea, base * height);
      }
    }
    return maxArea;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> matrix{{0, 0, 1}, {1, 1, 1}, {1, 0, 1}};
  s.largestSubmatrix(matrix);
  return 0;
}
