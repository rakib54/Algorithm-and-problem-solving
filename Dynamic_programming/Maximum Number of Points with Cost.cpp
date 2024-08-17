#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int n, m;
  long long maxPoints(vector<vector<int>> &points)
  {
    n = points.size();
    m = points[0].size();
    vector<long long> prev(m);

    for (int col = 0; col < m; col++)
    {
      prev[col] = points[0][col];
    }

    for (int i = 1; i < n; i++)
    { // starts with second row
      vector<long long> left(m, 0);
      vector<long long> right(m, 0);
      left[0] = prev[0];

      for (int j = 1; j < m; j++)
      {
        left[j] = max(prev[j], left[j - 1] - 1);
      }

      right[m - 1] = prev[m - 1];

      for (int j = m - 2; j >= 0; j--)
      {
        right[j] = max(prev[j], right[j + 1] - 1);
      }

      vector<long long> curr(m);

      for (int j = 0; j < m; j++)
      {
        curr[j] = points[i][j] + max(left[j], right[j]);
      }

      prev = curr;
    }

    return *max_element(begin(prev), end(prev));
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> points{{1, 2, 3}, {1, 5, 1}, {3, 1, 1}};
  solution.maxPoints(points);

  return 0;
}
