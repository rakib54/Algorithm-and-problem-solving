#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minTimeToVisitAllPoints(vector<vector<int>> &points)
  {
    int n = points.size();

    int ans = 0;

    for (int i = 0; i < n - 1; i++)
    {
      int vertical = abs(points[i + 1][1] - points[i][1]);
      int horizontal = abs(points[i + 1][0] - points[i][0]);
      int maxTime = max(vertical, horizontal);

      ans += maxTime;
    }

    return ans;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> points{{1, 1}, {3, 4}, {-1, 0}};
  s.minTimeToVisitAllPoints(points);
  return 0;
}
