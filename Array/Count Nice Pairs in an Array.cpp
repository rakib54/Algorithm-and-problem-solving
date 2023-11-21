#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  const int MOD = 1e9 + 7;
  int rev(int num)
  {
    int result = 0;

    while (num > 0)
    {
      int remainder = num % 10;
      num /= 10;
      result = result * 10 + remainder;
    }

    return result;
  }
  int countNicePairs(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> reverse(n, 0);

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
      reverse[i] = nums[i] - rev(nums[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      if (mp.find(reverse[i]) != mp.end())
      {
        ans = (ans + mp[reverse[i]]) % MOD;
      }
      mp[reverse[i]]++;
    }

    return ans % MOD;
  }
};

int main()
{
  Solution s;
  vector<int> nums{1, 11, 42, 97};
  s.countNicePairs(nums);

  return 0;
}
