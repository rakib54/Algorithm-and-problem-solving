#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
  {
    priority_queue<pair<double, pair<int, int>>> pq;

    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        pq.push({(double)arr[i] / arr[j], {arr[i], arr[j]}});
        if (pq.size() > k)
        {
          pq.pop();
        }
      }
    }

    auto result = pq.top();

    return {result.second.first, result.second.second};
  }
};

int main()
{
  Solution s;
  vector<int> arr{1, 2, 3, 5};
  int k = 3;
  s.kthSmallestPrimeFraction(arr, k);
  return 0;
}
