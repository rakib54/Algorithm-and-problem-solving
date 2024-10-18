#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int countSubsets(int idx, int currOr, vector<int> &nums, int &maxOr, vector<vector<int>> &dp)
  {
    if (idx == nums.size())
    {
      // subset with maximum or
      if (currOr == maxOr)
      {
        return 1;
      }
      return 0;
    }
    if (dp[idx][currOr] != -1)
    {
      return dp[idx][currOr];
    }

    // take this
    int take = countSubsets(idx + 1, currOr | nums[idx], nums, maxOr, dp);

    // not take
    int not_take = countSubsets(idx + 1, currOr, nums, maxOr, dp);

    return dp[idx][currOr] = take + not_take;
  }

  int countMaxOrSubsets(vector<int> &nums)
  {
    int maxOr = 0;
    int n = nums.size();

    // get maxOr with all elements or
    for (int num : nums)
    {
      maxOr = maxOr | num;
    }

    vector<vector<int>> dp(n + 1, vector<int>(maxOr + 1, -1));
    int currOr = 0;
    return countSubsets(0, currOr, nums, maxOr, dp);
  }
};

int main()
{
  Solution s;
  vector<int> nums{3, 2, 1, 5};
  s.countMaxOrSubsets(nums);

  return 0;
}
