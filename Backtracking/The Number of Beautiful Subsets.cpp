#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int result;
  int K;

  void solve(int i, vector<int> &nums, unordered_map<int, int> &mp)
  {
    if (i >= nums.size())
    {
      result++;
      return;
    }

    // take
    if (!mp[nums[i] - K] && !mp[nums[i] + K])
    {
      mp[nums[i]]++;          // do
      solve(i + 1, nums, mp); // explore
      mp[nums[i]]--;          // undo
    }

    // not take
    solve(i + 1, nums, mp);
  }
  int beautifulSubsets(vector<int> &nums, int k)
  {
    result = 0;
    K = k;

    unordered_map<int, int> mp;

    solve(0, nums, mp);

    return result - 1; // -1 for exclude empty subsets
  }
};

int main()
{
  Solution sol;
  vector<int> nums{2, 4, 6};
  int k = 2;

  sol.beautifulSubsets(nums, k);
  return 0;
}
