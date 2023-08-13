#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int n;
  int dp[100001];
  bool solve(int i, vector<int> &nums)
  {
    if (i >= n)
      return true;
    bool result = false;
    // rule no 1
    if (dp[i] != -1)
    {
      return dp[i];
    }
    if (i + 1 < n && nums[i] == nums[i + 1])
    {
      result |= solve(i + 2, nums);
    }

    // rule no 2
    if (i + 2 < n && nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2])
    {
      result |= solve(i + 3, nums);
    }
    // rule no 3
    if (i + 2 < n && nums[i + 2] - nums[i + 1] == 1 && nums[i + 1] - nums[i] == 1)
    {
      result |= solve(i + 3, nums);
    }
    // True | False = True

    return dp[i] = result;
  }
  bool validPartition(vector<int> &nums)
  {
    n = nums.size();
    memset(dp, -1, sizeof(dp));
    return solve(0, nums);
  }
};

int main()
{
  vector<int> nums{4, 4, 4, 5, 6};
  Solution s;
  s.validPartition(nums);

  return 0;
}