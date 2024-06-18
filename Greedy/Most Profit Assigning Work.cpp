#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
  {
    vector<pair<int, int>> work;
    int n = profit.size();

    for (int i = 0; i < n; i++)
    {
      work.push_back({difficulty[i], profit[i]});
    }
    sort(work.begin(), work.end());
    sort(worker.begin(), worker.end());

    int maxProfit = 0, idx = 0, bestProfit = 0;

    for (int i = 0; i < worker.size(); i++)
    {
      while (idx < n && work[idx].first <= worker[i])
      {
        bestProfit = max(bestProfit, work[idx].second);
        idx++;
      }
      maxProfit += bestProfit;
    }

    return maxProfit;
  }
};

int main()
{
  Solution s;
  vector<int> difficulty{2, 4, 6, 8, 10};
  vector<int> profit{10, 20, 30, 40, 50};
  vector<int> worker{4, 5, 6, 7};
  s.maxProfitAssignment(difficulty, profit, worker);
  return 0;
}
