#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int subarraysDivByK(vector<int> &nums, int k)
  {
    int n = nums.size();
    unordered_map<int, int> mp;
    int currSum = 0;
    mp[0] = 1;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
      currSum += nums[i];
      int mod = (currSum % k + k) % k;

      if (mp.find(mod) != mp.end())
      {
        count += mp[mod];
      }
      mp[mod]++;
    }
    return count;
  }
};

int main()
{
  Solution s;
  vector<int> nums{4, 5, 0, -2, -3, 1};
  int k = 5;
  s.subarraysDivByK(nums, k);
  return 0;
}
