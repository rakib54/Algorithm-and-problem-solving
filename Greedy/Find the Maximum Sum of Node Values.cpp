#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
  {
    ll sum = 0;
    int count = 0;
    ll minLoss = INT_MAX;

    for (ll num : nums)
    {
      if ((num ^ k) > num)
      {
        count++; // count Xor
        sum += num ^ k;
      }
      else
      {
        sum += num;
      }
      minLoss = min(minLoss, abs(num - (num ^ k)));
    }

    if (count % 2 != 0)
    {
      sum -= minLoss;
    }

    return sum;
  }
};

int main()
{
  Solution s;
  vector<int> nums{1, 2, 1};
  int k = 3;
  vector<vector<int>> edges{{0, 1}, {0, 2}};

  s.maximumValueSum(nums, k, edges);
  return 0;
}
