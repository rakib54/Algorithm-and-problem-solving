#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Graph
{
public:
  unordered_map<int, vector<pair<int, int>>> adj;
  priority_queue<pair<int, int>> pq;
  int N;
  Graph(int n, vector<vector<int>> &edges)
  {
    N = n;
    for (auto &edge : edges)
    {
      int u = edge[0];
      int v = edge[1];
      int cost = edge[2];

      adj[u].push_back({v, cost});
    }
  }

  void addEdge(vector<int> edge)
  {
    int u = edge[0];
    int v = edge[1];
    int cost = edge[2];
    adj[u].push_back({v, cost});
  }

  int shortestPath(int node1, int node2)
  {
    vector<int> result(N, INT_MAX);

    result[node1] = 0;
    pq.push({0, node1});

    while (!pq.empty())
    {
      int d = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      for (auto &vec : adj[node])
      {
        int adj_node = vec.first;
        int dist = vec.second;

        if (d + dist < result[adj_node])
        {
          result[adj_node] = d + dist;
          pq.push({d + dist, adj_node});
        }
      }
    }

    return result[node2] == INT_MAX ? -1 : result[node2];
  }
};

int main()
{
  
  return 0;
}
