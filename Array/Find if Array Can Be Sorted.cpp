#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool canSortArray(vector<int> &nums)
  {
    int n = nums.size();

    // bubble sort
    for (int i = 0; i < n - 1; i++)
    {
      int flag = 0;
      for (int j = 0; j < n - i - 1; j++)
      {
        if (nums[j] > nums[j + 1])
        {
          int a = __builtin_popcount(nums[j]);
          int b = __builtin_popcount(nums[j + 1]);

          if (a != b)
          {
            return false;
          }
          swap(nums[j], nums[j + 1]);

          flag = 1;
        }
      }
      if (flag == 0)
        break;
    }

    return true;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{8, 4, 2, 30, 15};
  solution.canSortArray(nums);

  return 0;
}
