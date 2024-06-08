#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool checkSubarraySum(vector<int> &nums, int k)
  {
    int n = nums.size();
    unordered_map<int, int> mp;
    mp[0] = -1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += nums[i];
      int remainder = sum % k;
      if (mp.find(remainder) != mp.end())
      { // if we see it in the past that means it should be modulo of k ans we just need to check the size
        int idx = mp[remainder];
        int size = i - idx;
        if (size >= 2)
        {
          return true;
        }
      }
      else
      {
        mp[remainder] = i;
      }
    }

    return false;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{23, 2, 4, 6, 7};
  solution.checkSubarraySum(nums, 6);
  return 0;
}