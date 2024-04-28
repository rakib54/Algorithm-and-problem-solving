#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> count;
  int N;
  int root_result = 0;

  int dfsRoot(unordered_map<int, vector<int>> &adj, int curr_node, int prev_node, int curr_depth)
  {
    int total_count = 1;
    root_result += curr_depth;

    for (auto &child : adj[curr_node])
    {
      if (child == prev_node)
      {
        continue;
      }
      total_count += dfsRoot(adj, child, curr_node, curr_depth + 1);
    }

    count[curr_node] = total_count;

    return total_count;
  }

  void DFS(unordered_map<int, vector<int>> &adj, int parent_node, int prev_node, vector<int> &result)
  {
    for (auto &child : adj[parent_node])
    {
      if (child == prev_node)
      {
        continue;
      }
      result[child] = result[parent_node] - count[child] + (N - count[child]);

      DFS(adj, child, parent_node, result);
    }
  }

  vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
  {
    count.resize(n, 0);
    N = n;
    unordered_map<int, vector<int>> adj;

    for (auto edge : edges)
    {
      int u = edge[0];
      int v = edge[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfsRoot(adj, 0, -1, 0);
    vector<int> result(n, 0);
    result[0] = root_result;
    DFS(adj, 0, -1, result);

    return result;
  }
};

int main()
{
  Solution s;
  int n = 6;
  vector<vector<int>> edges{{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
  s.sumOfDistancesInTree(n, edges);
  return 0;
}
