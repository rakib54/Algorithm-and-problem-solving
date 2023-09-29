#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool isMonotonic(vector<int> &nums)
  {
    bool increasing = true;
    bool decreasing = true;

    for (int i = 0; i < nums.size() - 1; i++)
    {

      if (nums[i] > nums[i + 1])
      { // if not increasing
        increasing = false;
      }
      else if (nums[i] < nums[i + 1])
      { // if not decreasing
        decreasing = false;
      }

      if (!increasing && !decreasing)
      {
        return false;
      }
    }

    return true;
  }
};

int main()
{
  vector<int> nums{1, 2, 2, 3};
  Solution s;
  s.isMonotonic(nums);

  return 0;
}
