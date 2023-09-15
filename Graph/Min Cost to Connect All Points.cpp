#include <bits/stdc++.h>
using namespace std;
#define ll long long

typedef pair<int, int> P;

class Solution
{
public:
  int Prims(vector<vector<P>> &adj, int n)
  {
    priority_queue<P, vector<P>, greater<P>> pq;

    pq.push({0, 0});

    vector<bool> inMST(n, false);
    int sum = 0;

    while (!pq.empty())
    {
      auto p = pq.top();
      pq.pop();

      int wt = p.first;
      int node = p.second;

      if (inMST[node] == true)
      {
        continue;
      }

      // mark visited
      inMST[node] = true;
      sum += wt;

      for (auto &tmp : adj[node])
      {
        int neighbor = tmp.first;
        int neighbor_wt = tmp.second;

        if (inMST[neighbor] == false)
        {
          pq.push({neighbor_wt, neighbor});
        }
      }
    }
    return sum;
  }

  int minCostConnectPoints(vector<vector<int>> &points)
  {
    int n = points.size();

    vector<vector<P>> adj(n);

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        int x1 = points[i][0];
        int y1 = points[i][1];

        int x2 = points[j][0];
        int y2 = points[j][1];
        int dist = abs(x1 - x2) + abs(y1 - y2);

        adj[i].push_back({j, dist});
        adj[j].push_back({i, dist});
      }
    }

    return Prims(adj, n);
  }
};

int main()
{
  Solution s;
  vector<vector<int>> points{{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
  s.minCostConnectPoints(points);

  return 0;
}
