#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int findMinArrowShots(vector<vector<int>> &points)
  {
    sort(points.begin(), points.end());
    int n = points.size();
    int ans = 1;
    int prevEnd = points[0][1];

    for (int i = 1; i < n; i++)
    { // start with second points
      if (prevEnd < points[i][0])
      {
        ans++;
        prevEnd = points[i][1];
      }
      else
      { // if overlaped
        prevEnd = min(prevEnd, points[i][1]);
      }
    }

    return ans;
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> points{{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  solution.findMinArrowShots(points);
  return 0;
}
