#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  typedef pair<int, int> P;
  vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
  {
    int n = nums.size();
    priority_queue<P, vector<P>, greater<P>> pq;

    for (int i = 0; i < n; i++)
    {
      pq.push({nums[i], i});
    }

    while (k--)
    {
      auto top = pq.top();
      int idx = top.second;
      pq.pop();

      nums[idx] *= multiplier;
      pq.push({nums[idx], idx});
    }

    return nums;
  }
};

int main()
{
  Solution s;
  vector<int> nums{2, 1, 3, 5, 6};
  int k;
  int multiplier;

  s.getFinalState(nums, k, multiplier);

  return 0;
}
