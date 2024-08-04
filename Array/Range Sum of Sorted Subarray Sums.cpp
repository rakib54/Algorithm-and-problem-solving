#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int mod = 1e9 + 7;
  int rangeSum(vector<int> &nums, int n, int left, int right)
  {
    vector<int> sum;
    int result = 0;

    for (int i = 0; i < n; i++)
    {
      int prefix = 0;
      for (int j = i; j < n; j++)
      {
        prefix += nums[j];
        sum.push_back(prefix);
      }
    }

    sort(sum.begin(), sum.end());

    for (int i = left - 1; i < right; i++)
    {
      result = (result + sum[i]) % mod;
    }

    return result;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{1, 2, 3, 4};
  int n = 4, left = 1, right = 5;

  solution.rangeSum(nums, n, left, right);

  return 0;
}
