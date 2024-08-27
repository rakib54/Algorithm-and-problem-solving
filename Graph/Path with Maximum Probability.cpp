#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  void dijkstra(int start, int end, unordered_map<int, vector<pair<int, double>>> &adj, vector<double> &result)
  {
    priority_queue<pair<double, int>> pq;
    pq.push({1.0, start});

    while (!pq.empty())
    {
      auto top = pq.top();
      double curr_prob = top.first;
      int curr_node = top.second;
      pq.pop();

      for (auto node : adj[curr_node])
      {
        double adj_prob = node.second;
        int adj_node = node.first;

        if (result[adj_node] < curr_prob * adj_prob)
        {
          result[adj_node] = curr_prob * adj_prob;
          pq.push({curr_prob * adj_prob, adj_node});
        }
      }
    }
  }
  double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
  {
    unordered_map<int, vector<pair<int, double>>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
      int u = edges[i][0];
      int v = edges[i][1];
      double prob = succProb[i];
      adj[u].push_back({v, prob});
      adj[v].push_back({u, prob});
    }

    vector<double> result(n, 0);
    dijkstra(start_node, end_node, adj, result);

    return result[end_node];
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> edges{{0, 1}, {1, 2}, {0, 2}};
  vector<double> succProb{0.5, 0.5, 0.2};
  int start_node = 0;
  int end_node = 2;
  int n = 3;

  solution.maxProbability(n, edges, succProb, start_node, end_node);

  return 0;
}
