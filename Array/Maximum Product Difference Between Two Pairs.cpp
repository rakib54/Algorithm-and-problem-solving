#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int maxProductDifference(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int ans = (nums[n - 1] * nums[n - 2]) - (nums[0] * nums[1]);

    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums{5, 6, 2, 7, 4};
  s.maxProductDifference(nums);

  return 0;
}
