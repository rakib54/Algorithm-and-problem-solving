#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  void dijkstra(int n, unordered_map<int, vector<pair<int, int>>> &adj, vector<int> &result, int src)
  {
    priority_queue<pair<int, int>> pq;
    pq.push({0, src});
    result[src] = 0;

    while (!pq.empty())
    {
      int distance = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      for (auto &p : adj[node])
      {
        int adjnode = p.first;
        int dist = p.second;

        if (distance + dist < result[adjnode])
        {
          result[adjnode] = distance + dist;
          pq.push({distance + dist, adjnode});
        }
      }
    }
  }

  int findResultCity(int n, vector<vector<int>> SPM, int distanceThreshold)
  {
    int resultCity = -1;
    int leastReachCityCount = INT_MAX;

    for (int i = 0; i < n; i++)
    {
      int countReach = 0;
      for (int j = 0; j < n; j++)
      {
        if (i != j && SPM[i][j] <= distanceThreshold)
        {
          countReach++;
        }
      }
      if (countReach <= leastReachCityCount)
      {
        leastReachCityCount = min(leastReachCityCount, countReach);
        resultCity = i;
      }
    }

    return resultCity;
  }
  int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
  {
    vector<vector<int>> shortestPathMatrix(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++)
    {
      shortestPathMatrix[i][i] = 0; // i -> i = 0
    }

    unordered_map<int, vector<pair<int, int>>> adj;

    for (auto &edge : edges)
    {
      int u = edge[0];
      int v = edge[1];
      int distance = edge[2];
      adj[u].push_back({v, distance});
      adj[v].push_back({u, distance});
    }

    for (int i = 0; i < n; i++)
    {
      dijkstra(n, adj, shortestPathMatrix[i], i); // shortestPathMatrix[i] = ith row of the matrix
    }

    // find the city
    return findResultCity(n, shortestPathMatrix, distanceThreshold);
  }
};

int main()
{
  int n = 4;
  vector<vector<int>> edges{{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
  int distanceThreshold = 4;

  Solution solution;
  solution.findTheCity(n, edges, distanceThreshold);

  return 0;
}
