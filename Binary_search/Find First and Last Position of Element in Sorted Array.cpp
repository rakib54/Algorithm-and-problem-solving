#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int lower_bound(vector<int> &nums, int low, int high, int target)
  {
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (nums[mid] < target)
      {
        low = mid + 1;
      }
      else
        high = mid - 1;
    }
    return low;
  }
  vector<int> searchRange(vector<int> &nums, int target)
  {
    int starting_pos = lower_bound(nums, 0, nums.size() - 1, target);
    int ending_pos = lower_bound(nums, 0, nums.size() - 1, target + 1) - 1;

    if (starting_pos <= ending_pos)
    {
      return {starting_pos, ending_pos};
    }
    return {-1, -1};
  }
};

int main()
{
  Solution s;
  vector<int> nums{1, 2, 3, 4, 6, 7, 7, 7};
  int target = 7;
  s.searchRange(nums, target);
  return 0;
}
