#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int findMaxK(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());

    int n = nums.size();

    for (int i = n - 1; i >= 0; i--)
    {
      if (nums[i] > 0 && binary_search(nums.begin(), nums.end(), -nums[i]))
      {
        return nums[i];
      }
    }

    return -1;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{-1, 10, 6, 7, -7, 1};
  solution.findMaxK(nums);
  return 0;
}
