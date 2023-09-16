/*
problem link: https://leetcode.com/problems/path-with-minimum-effort/description/?envType=daily-question&envId=2023-09-16

//dijkstra algorithm
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  typedef pair<int, pair<int, int>> P;
  vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  int minimumEffortPath(vector<vector<int>> &heights)
  {
    int m = heights.size();
    int n = heights[0].size();

    vector<vector<int>> result(m, vector<int>(n, INT_MAX));

    result[0][0] = 0;

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, {0, 0}});

    while (!pq.empty())
    {

      int diff = pq.top().first;
      auto coord = pq.top().second;
      pq.pop();

      int x = coord.first;
      int y = coord.second;

      for (auto dir : directions)
      {
        int new_x = x + dir[0];
        int new_y = y + dir[1];

        if (new_x < m && new_y < n && new_x >= 0 && new_y >= 0)
        {
          int abs_diff = abs(heights[x][y] - heights[new_x][new_y]);

          int max_diff = max(diff, abs_diff);

          if (result[new_x][new_y] > max_diff)
          { // if found smaller difference
            result[new_x][new_y] = max_diff;
            pq.push({max_diff, {new_x, new_y}});
          }
        }
      }
    }
    return result[m - 1][n - 1];
  }
};

int main()
{
  Solution s;
  vector<vector<int>> heights{{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
  s.minimumEffortPath(heights);

  return 0;
}
