#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  typedef pair<int, int> P;
  int shortestPathLength(vector<vector<int>> &graph)
  {
    int n = graph.size();

    if (n == 0 || n == 1)
    {
      return 0;
    }

    queue<P> q;
    set<P> visited;

    for (int i = 0; i < n; i++)
    {
      int mask = 1 << i;
      q.push({i, mask});
    }
    int path = 0;
    int allVisitedState = (1 << n) - 1; // or pow(2,n) + 1

    while (!q.empty())
    {
      int size = q.size();
      path++;

      while (size--)
      {
        P curr = q.front();
        q.pop();

        int curr_node = curr.first;
        int curr_mask = curr.second;

        for (int &adj : graph[curr_node])
        {
          int nextMask = curr_mask | (1 << adj);

          if (nextMask == allVisitedState)
          {
            return path;
          }

          if (visited.find({adj, nextMask}) == visited.end())
          {
            q.push({adj, nextMask});
            visited.insert({adj, nextMask});
          }
        }
      }
    }
    return -1;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> graph{{1, 2, 3}, {0}, {0}, {0}};
  s.shortestPathLength(graph);

  return 0;
}
