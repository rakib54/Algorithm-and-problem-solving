#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n - i - 1; j++)
      {
        if (nums[j] > nums[j + 1])
        {
          swap(nums[j], nums[j + 1]);
        }
      }
    }
  }
};

int main()
{
  vector<int> nums{2, 0, 2, 1, 1, 0};
  Solution s;
  s.sortColors(nums);
  return 0;
}
