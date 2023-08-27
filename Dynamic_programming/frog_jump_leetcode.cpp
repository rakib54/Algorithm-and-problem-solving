#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int n;
  unordered_map<int, int> mp;
  int dp[2001][2001];

  bool solve(int idx, int k, vector<int> &nums)
  {
    if (idx == n - 1)
    {
      return true;
    }
    if (dp[idx][k] != -1)
    {
      return dp[idx][k];
    }

    bool forward = false;
    if (mp.find(nums[idx] + k + 1) != mp.end())
    {
      forward = solve(mp[nums[idx] + k + 1], k + 1, nums);
    }
    bool sameMove = false;
    if (mp.find(nums[idx] + k) != mp.end())
    {
      sameMove = solve(mp[nums[idx] + k], k, nums);
    }
    bool backward = false;
    if (k - 1 > 0 && mp.find(nums[idx] + k - 1) != mp.end())
    {
      backward = solve(mp[nums[idx] + k - 1], k - 1, nums);
    }

    return dp[idx][k] = forward || backward || sameMove;
  }
  bool canCross(vector<int> &stones)
  {
    if (stones[1] - stones[0] > 1)
    {
      return false;
    }
    n = stones.size();
    for (int i = 0; i < n; i++)
    {
      mp[stones[i]] = i;
    }

    memset(dp, -1, sizeof(dp));

    return solve(1, 1, stones);
  }
};

int main()
{
  Solution solution;
  vector<int> stones{0, 1, 3, 5, 6, 8, 12, 17};
  solution.canCross(stones);

  return 0;
}
