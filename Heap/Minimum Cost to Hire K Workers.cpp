#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
  {
    int n = quality.size();
    double result = DBL_MAX;

    vector<pair<double, int>> worker_ratio(n);

    for (int i = 0; i < n; i++)
    {
      worker_ratio[i] = make_pair((double)wage[i] / quality[i], quality[i]);
    }

    sort(worker_ratio.begin(), worker_ratio.end());

    int sum_quality = 0;
    priority_queue<int> pq;

    for (int i = 0; i < k; i++)
    {
      pq.push(worker_ratio[i].second);
      sum_quality += worker_ratio[i].second;
    }
    double manager_ratio = worker_ratio[k - 1].first;

    result = sum_quality * manager_ratio; // find k - 1th result first

    for (int manager = k; manager < n; manager++)
    {
      manager_ratio = worker_ratio[manager].first;
      pq.push(worker_ratio[manager].second);

      sum_quality += worker_ratio[manager].second;

      if (pq.size() > k)
      {
        sum_quality -= pq.top();
        pq.pop();
      }

      result = min(result, sum_quality * manager_ratio);
    }

    return result;
  }
};

int main()
{
  Solution solution;
  vector<int> quality{10, 20, 5};
  vector<int> wage{70, 50, 30};
  int k = 2;
  return 0;
}
