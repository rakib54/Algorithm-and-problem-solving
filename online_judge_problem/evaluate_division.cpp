#include <bits/stdc++.h>
using namespace std;
#define ll long long

unordered_map<string, vector<pair<string, double>>> adjlist;
vector<double> ans;

bool dfs(string dividend, string divisor, unordered_set<string> &vis, double currprod)
{
  if (vis.find(dividend) != vis.end())
  {
    return false;
  }
  vis.insert(dividend);
  if (dividend == divisor)
  {
    ans.push_back(currprod);
    return true;
  }
  bool found = false;
  for (auto node : adjlist[dividend])
  {
    found = dfs(node.first, divisor, vis, currprod * node.second);
    if (found)
    {
      return true;
    }
  }
  return false;
}

void solve()
{
  vector<vector<string>> equations{{"a", "b"}, {"b", "c"}};
  vector<double> values{2.0, 3.0};
  vector<vector<string>> queries{{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
  int n = equations.size();
  int m = queries.size();
  adjlist.clear();
  ans.clear();

  for (int i = 0; i < n; i++)
  {
    string dividend = equations[i][0];
    string divisor = equations[i][1];
    adjlist[dividend].push_back({divisor, values[i]});
    adjlist[divisor].push_back({dividend, 1.0 / values[i]});
  }

  for (auto &q : queries)
  {
    string dividend = q[0];
    string divisor = q[1];
    if (adjlist.find(dividend) == adjlist.end() || adjlist.find(divisor) == adjlist.end())
    {
      ans.push_back(-1.0);
    }
    else
    {
      unordered_set<string> vis;
      if (!dfs(dividend, divisor, vis, 1.0))
      {
        ans.push_back(-1);
      }
    }
  }
  for (auto i : ans)
  {
    cout << i << " ";
  }
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
