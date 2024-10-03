#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minSubarray(vector<int> &nums, int p)
  {
    int n = nums.size();

    int sum = 0;

    for (int num : nums)
    {
      sum = (sum + num) % p;
    }
    int target = sum % p;

    if (target == 0)
    { // no need to remove any subarray
      return 0;
    }

    int result = n;
    unordered_map<int, int> mp;
    int curr = 0;

    mp[0] = -1;

    for (int j = 0; j < n; j++)
    {
      curr = (curr + nums[j]) % p; // curr mod

      int remaining = (curr - target + p) % p;

      if (mp.find(remaining) != mp.end())
      {
        result = min(result, j - mp[remaining]);
      }

      mp[curr] = j;
    }

    return result == n ? -1 : result;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{3, 1, 4, 2};
  int p = 6;

  solution.minSubarray(nums, p);

  return 0;
}
