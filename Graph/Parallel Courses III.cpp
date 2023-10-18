#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
  {
    unordered_map<int, vector<int>> adj;
    vector<int> maxTime(n + 1, 0);
    vector<int> indegree(n + 1, 0);
    queue<int> q;

    for (auto relation : relations)
    {
      int u = relation[0];
      int v = relation[1];
      adj[u].push_back(v);
      indegree[v]++;
    }

    for (int i = 1; i <= n; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
        maxTime[i] = time[i - 1]; // for time 0 base indexing
      }
    }

    while (!q.empty())
    {
      int node = q.front();
      q.pop();

      for (int adj_node : adj[node])
      {
        indegree[adj_node]--;

        if (indegree[adj_node] == 0)
        {
          q.push(adj_node);
        }
        maxTime[adj_node] = max(maxTime[adj_node], maxTime[node] + time[adj_node - 1]);
      }
    }

    return *max_element(maxTime.begin(), maxTime.end()); // max time need to complete all courses
  }
};

int main()
{
  Solution s;
  int n = 5;
  vector<vector<int>> relations{{1, 3}, {2, 3}};
  vector<int> time{3, 2, 5};
  s.minimumTime(n, relations, time);
  return 0;
}
