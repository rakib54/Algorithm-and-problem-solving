#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dfs(int headID, vector<int> &informTime, vector<int> adj[])
{
  int maxtime = 0;
  for (int it : adj[headID])
  {
    maxtime = max(maxtime, dfs(it, informTime, adj));
  }
  return informTime[headID] + maxtime;
}

void solve()
{
  int n = 6;
  int headID = 2;
  vector<int> manager{2, 2, -1, 2, 2, 2};
  vector<int> informTime{0, 0, 1, 0, 0, 0};
  vector<int> adj[n];
  for (int i = 0; i < manager.size(); i++)
  {
    if (manager[i] != -1)
    {
      adj[manager[i]].push_back(i);
    }
  }
  cout << dfs(headID, informTime, adj);
}

int main()
{
  ll test = 1;
  while (test--)
  {
    solve();
  }
  return 0;
}
