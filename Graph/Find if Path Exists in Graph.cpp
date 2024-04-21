#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  void dfs(vector<vector<int>> &adj, int source, vector<int> &visited)
  {
    visited[source] = 1;

    for (int neighbor : adj[source])
    {
      if (visited[neighbor] != 1)
      { // base case
        dfs(adj, neighbor, visited);
      }
    }
  }

  bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
  {
    vector<vector<int>> adj(n);
    for (auto edge : edges)
    {
      int u = edge[0];
      int v = edge[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> visited(n, 0);

    dfs(adj, source, visited);

    return visited[destination] == 1;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> edge{{0, 1}, {1, 2}, {2, 0}};
  int n = 3, source = 0, destination = 2;
  s.validPath(n, edge, source, destination);

  return 0;
}
