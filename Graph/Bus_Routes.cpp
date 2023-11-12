#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
  {

    if (source == target)
      return 0;
    unordered_map<int, vector<int>> adj;

    for (int route = 0; route < routes.size(); route++)
    {
      for (auto &stop : routes[route])
      {
        adj[stop].push_back(route);
      }
    }
    queue<int> q;
    vector<bool> visited(501, false);
    for (auto &route : adj[source])
    {
      q.push(route);
      visited[route] = true;
    }

    int bus_count = 1;
    while (!q.empty())
    {
      int size = q.size();

      while (size--)
      {
        int route = q.front();
        q.pop();

        for (auto &stop : routes[route])
        {
          if (stop == target)
          {
            return bus_count;
          }

          for (auto &nextStop : adj[stop])
          {
            if (visited[nextStop] == false)
            {
              visited[nextStop] = true;
              q.push(nextStop);
            }
          }
        }
      }
      bus_count++;
    }
    return -1;
  }
};

int main()
{
  vector<vector<int>> routes{{1, 2, 7}, {3, 6, 7}};
  int source = 1, target = 6;

  Solution s;
  s.numBusesToDestination(routes, source, target);

  return 0;
}
