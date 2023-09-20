#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minOperations(vector<int> &nums, int x)
  {
    int n = nums.size();
    unordered_map<int, int> mp;
    mp[0] = -1; // corner case

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
      sum += nums[i];
      mp[sum] = i;
    }

    if (sum < x)
    { // corner case
      return -1;
    }

    int remainingSum = sum - x;
    int longestSubArray = INT_MIN;

    sum = 0;

    for (int i = 0; i < n; i++)
    {
      sum += nums[i];

      int findSum = sum - remainingSum;

      if (mp.find(findSum) != mp.end())
      {
        int idx = mp[findSum];
        longestSubArray = max(longestSubArray, i - idx);
      }
    }

    return longestSubArray == INT_MIN ? -1 : (n - longestSubArray);
  }
};

int main()
{
  Solution s;
  vector<int> nums{1, 1, 4, 2, 3};
  s.minOperations(nums, 5);
  return 0;
}
