#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    int slow = nums[0];
    int fast = nums[0];

    slow = nums[slow];
    fast = nums[nums[fast]];

    // detect cycle
    while (slow != fast)
    {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    slow = nums[0];
    // move slow and fast pointers by linearly
    while (slow != fast)
    {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;
  }
};

int main()
{
  Solution s;
  vector<int> nums{1, 3, 4, 2, 2};
  s.findDuplicate(nums);

  return 0;
}

// another approach
class Solution1
{
public:
  int findDuplicate(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 1; i++)
    {
      if (nums[i] == nums[i + 1])
      {
        return nums[i];
      }
    }

    return -1;
  }
};
