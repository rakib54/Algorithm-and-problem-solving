#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool search(vector<int> &nums, int target)
  {
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target)
      {
        return true;
      }
      if (nums[low] == nums[mid] && nums[mid] == nums[high])
      { // for duplicates
        low++;
        high--;
      }
      else if (nums[low] <= nums[mid])
      { // left sorted
        if (nums[low] <= target && target <= nums[mid])
        {
          high = mid - 1;
        }
        else
        {
          low = mid + 1;
        }
      }
      else
      { // right sorted
        if (nums[mid] <= target && target <= nums[high])
        {
          low = mid + 1;
        }
        else
        {
          high = mid - 1;
        }
      }
    }
    return false;
  }
};

int main()
{
  Solution solution;
  vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
  int target = 0;
  cout << solution.search(nums, target);

  return 0;
}