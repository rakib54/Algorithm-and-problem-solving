#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  long long maximumImportance(int n, vector<vector<int>> &roads)
  {
    map<int, int> indegree;
    for (auto road : roads)
    {
      indegree[road[0]]++;
      indegree[road[1]]++;
    }
    vector<long long> v;
    for (auto i : indegree)
    {
      v.push_back(i.second);
    }

    sort(v.begin(), v.end());

    long long sum = 0;

    for (int i = v.size() - 1; i >= 0; i--)
    {
      sum += (v[i] * n);
      n--;
    }

    return sum;
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> roads{{0, 3}, {2, 4}, {1, 3}};
  int n = 5;
  solution.maximumImportance(n, roads);
  return 0;
}
