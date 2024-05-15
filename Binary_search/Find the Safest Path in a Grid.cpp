#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int n;
  vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

  bool checkSafestFactor(vector<vector<int>> &distNearestTheves, int safe)
  {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    if (distNearestTheves[0][0] < safe)
      return false;

    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
      int curr_i = q.front().first;
      int curr_j = q.front().second;
      q.pop();

      if (curr_i == n - 1 && curr_j == n - 1)
      {
        return true;
      }

      for (vector<int> &dir : directions)
      {
        int new_i = curr_i + dir[0];
        int new_j = curr_j + dir[1];

        // check edge case
        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && visited[new_i][new_j] != true)
        {
          if (distNearestTheves[new_i][new_j] < safe)
          {
            continue; // reject it
          }
          q.push({new_i, new_j});
          visited[new_i][new_j] = true;
        }
      }
    }
    return false;
  }

  int maximumSafenessFactor(vector<vector<int>> &grid)
  {
    n = grid.size();

    // precalculation of distance of nearest theves
    vector<vector<int>> distNearestTheves(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n, 0));

    // find the theves and push to the queue
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          q.push({i, j});
          visited[i][j] = true;
        }
      }
    }
    int level = 0;

    while (!q.empty())
    { // do level order travarsal
      int size = q.size();

      while (size--)
      {
        int curr_i = q.front().first;
        int curr_j = q.front().second;
        q.pop();

        distNearestTheves[curr_i][curr_j] = level;

        for (vector<int> &dir : directions)
        {
          int new_i = curr_i + dir[0];
          int new_j = curr_j + dir[1];

          // check edge case
          if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= n || visited[new_i][new_j] == true)
          {
            continue;
          }

          q.push({new_i, new_j});
          visited[new_i][new_j] = true;
        }
      }
      level++;
    }

    int l = 0, r = 400;
    int result = 0;

    while (l <= r)
    {
      int mid = l + (r - l) / 2;

      if (checkSafestFactor(distNearestTheves, mid))
      {
        result = mid;
        l = mid + 1;
      }
      else
      {
        r = mid - 1;
      }
    }

    return result;
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> grid{{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
  solution.maximumSafenessFactor(grid);
  return 0;
}
