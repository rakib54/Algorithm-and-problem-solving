#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int n;
  int dp[201][1001];
  int solve(int idx, vector<int> &nums, int target)
  {
    if (idx >= n || target < 0) // target can't be negative or less than 0
    {
      return 0;
    }
    if (target == 0)
      return 1;

    if (dp[idx][target] != -1)
    {
      return dp[idx][target];
    }

    int take = solve(0, nums, target - nums[idx]); // start with 0 again to make combination
    int not_take = solve(idx + 1, nums, target);

    return dp[idx][target] = take + not_take;
  }

  int combinationSum4(vector<int> &nums, int target)
  {
    n = nums.size();
    memset(dp, -1, sizeof(dp));

    return solve(0, nums, target);
  }
};

int main()
{
  Solution solution;
  vector<int> nums{1, 2, 3};
  int target = 7;
  solution.combinationSum4(nums, target);

  return 0;
}
