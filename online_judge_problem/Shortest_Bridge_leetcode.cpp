#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> direction{
    {-1, 0},
    {0, -1},
    {0, 1},
    {1, 0}};

int n, m;

bool issafe(int i, int j)
{
  return i >= 0 && i < n && j >= 0 && j < m;
}
void dfs(vector<vector<int>> &grid, set<pair<int, int>> &visited, int i, int j)
{
  if (!issafe(i, j) || grid[i][j] == 0 || visited.find({i, j}) != visited.end())
  {
    return;
  }
  visited.insert({i, j});

  for (auto &dir : direction)
  {
    int i_new = i + dir[0];
    int j_new = j + dir[1];
    dfs(grid, visited, i_new, j_new);
  }
}

int bfs(vector<vector<int>> &grid, set<pair<int, int>> &visited)
{
  queue<pair<int, int>> q;

  for (auto &it : visited)
  {
    q.push(it);
  }
  int level = 0;
  while (!q.empty())
  {
    int s = q.size();
    while (s--)
    {
      auto node = q.front();
      q.pop();
      int i = node.first;
      int j = node.second;

      for (auto &dir : direction)
      {
        int i_new = i + dir[0];
        int j_new = j + dir[1];

        if (issafe(i_new, j_new) && visited.find({i_new, j_new}) == visited.end())
        {
          if (grid[i_new][j_new] == 1)
          {
            return level; // we found second island
          }
          visited.insert({i_new, j_new});
          q.push({i_new, j_new});
        }
      }
    }
    level++;
  }
  return level;
}

void solve()
{
  vector<vector<int>> grid{{0, 1}, {1, 0}};
  n = grid.size();
  m = grid[0].size();

  set<pair<int, int>> visited;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (grid[i][j] == 1)
      { // mark all 1 cell of island
        dfs(grid, visited, i, j);
        cout << bfs(grid, visited); // return
        return;
      }
    }
  }
  cout << -1;
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
