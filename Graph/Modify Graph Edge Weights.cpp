#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  const int LargeVal = 2e9;
  typedef pair<ll, ll> P;

  ll dijkstra(vector<vector<int>> &edges, int n, int source, int destination)
  {
    // make the graph excluding -1
    unordered_map<ll, vector<pair<ll, ll>>> adj;

    for (vector<int> &edge : edges)
    {
      if (edge[2] == -1)
        continue;
      int u = edge[0];
      int v = edge[1];
      int wt = edge[2];

      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    vector<ll> result(n, INT_MAX);
    vector<bool> visited(n, false);
    result[source] = 0;
    pq.push({0, source}); // dist , src

    while (!pq.empty())
    {
      auto curr = pq.top();
      ll currDist = curr.first;
      ll node = curr.second;
      pq.pop();

      if (visited[node] == true)
      {
        continue;
      }

      visited[node] = true;

      for (auto &[neighbour, wt] : adj[node])
      {
        if (currDist + wt < result[neighbour])
        {
          result[neighbour] = currDist + wt;
          pq.push({result[neighbour], neighbour});
        }
      }
    }

    return result[destination];
  }

  vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target)
  {
    ll currentShortestDist = dijkstra(edges, n, source, destination);

    if (currentShortestDist < target)
    { // impossible case
      return {};
    }

    bool matchedTarget = (currentShortestDist == target);

    for (vector<int> &edge : edges)
    {
      if (edge[2] == -1)
      {
        edge[2] = (matchedTarget == true) ? LargeVal : 1;

        if (matchedTarget != true)
        {
          ll newShortestDist = dijkstra(edges, n, source, destination);

          if (newShortestDist <= target)
          {
            matchedTarget = true;
            edge[2] += (target - newShortestDist);
          }
        }
      }
    }

    if (matchedTarget == false)
    {
      return {};
    }

    return edges;
  }
};

int main()
{
  Solution s;
  int n = 5, source = 0, destination = 1, target = 5;
  vector<vector<int>> edges{{4, 1, -1}, {2, 0, -1}, {0, 3, -1}, {4, 3, -1}};

  s.modifiedGraphEdges(n, edges, source, destination, target);

  return 0;
}
