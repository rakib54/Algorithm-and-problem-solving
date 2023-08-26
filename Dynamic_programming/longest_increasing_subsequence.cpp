#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int dp[2500][2500];
  int n;
  int solve(vector<int> &nums, int prev, int curr)
  {
    if (curr >= n)
    {
      return 0;
    }

    if (prev != -1 && dp[prev][curr] != -1)
    {
      return dp[prev][curr];
    }

    int take = 0;
    if (prev == -1 || nums[prev] < nums[curr])
    {
      take = 1 + solve(nums, curr, curr + 1);
    }
    int skip = solve(nums, prev, curr + 1);

    if (prev != -1)
    {
      dp[prev][curr] = max(take, skip);
    }
    return max(take, skip);
  }

  int lengthOfLIS(vector<int> &nums)
  {
    n = nums.size();
    memset(dp, -1, sizeof(dp));

    return solve(nums, -1, 0);
  }
};

int main()
{
  Solution solution;
  vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
  solution.lengthOfLIS(nums);

  return 0;
}
