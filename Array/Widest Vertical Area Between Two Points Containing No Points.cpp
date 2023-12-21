#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int maxWidthOfVerticalArea(vector<vector<int>> &points)
  {
    sort(points.begin(), points.end());
    int n = points.size();

    int maxWidth = 0;

    for (int i = 0; i < n - 1; i++)
    {
      int width = abs(points[i][0] - points[i + 1][0]);

      maxWidth = max(maxWidth, width);
    }

    return maxWidth;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> points{{8, 7}, {9, 9}, {7, 4}};
  s.maxWidthOfVerticalArea(points);
  return 0;
}
