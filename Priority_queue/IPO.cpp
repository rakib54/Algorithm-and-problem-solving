#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
  {
    int n = profits.size();
    vector<pair<int, int>> projects;

    for (int i = 0; i < n; i++)
    {
      projects.push_back({capital[i], profits[i]});
    }

    sort(projects.begin(), projects.end());

    priority_queue<int> pq;

    int j = 0;

    for (int i = 1; i <= k; i++)
    {
      while (j < n && projects[j].first <= w)
      {
        pq.push(projects[j++].second);
      }
      if (!pq.empty())
      {
        w += pq.top();
        pq.pop();
      }
    }

    return w;
  }
};

int main()
{
  Solution solution;
  vector<int> profits{1, 2, 3};
  vector<int> capital{0, 1, 1};
  int k = 2, w = 0;

  solution.findMaximizedCapital(k, w, profits, capital);

  return 0;
}
