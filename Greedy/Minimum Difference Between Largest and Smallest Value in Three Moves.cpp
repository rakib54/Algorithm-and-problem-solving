#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minDifference(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    if (n <= 4)
    {
      return 0;
    }
    int ans = INT_MAX;

    ans = min(ans, nums[n - 1] - nums[3]);
    ans = min(ans, nums[n - 4] - nums[0]);
    ans = min(ans, nums[n - 3] - nums[1]);
    ans = min(ans, nums[n - 2] - nums[2]);

    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums{1, 5, 0, 10, 14};
  s.minDifference(nums);
  return 0;
}

// vector<nums>{0,2,3,5,6,10,11,14}; example to understand the question
