#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int findCenter(vector<vector<int>> &edges)
  {
    unordered_map<int, int> mp;

    for (auto edge : edges)
    {
      mp[edge[0]]++;
      mp[edge[1]]++;
    }

    for (auto i : mp)
    {
      if (i.second == mp.size() - 1)
      {
        return i.first;
      }
    }

    return -1;
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> edges{{1, 2}, {2, 3}, {4, 2}};

  solution.findCenter(edges);
  return 0;
}
