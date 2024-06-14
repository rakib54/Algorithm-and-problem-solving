#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minIncrementForUnique(vector<int> &nums)
  {
    int count = 0;
    int n = nums.size();
    sort(begin(nums), end(nums));

    for (int i = 1; i < n; i++)
    {
      int prev = nums[i - 1];
      int curr = nums[i];

      if (prev >= curr)
      {
        count += prev - curr + 1;
        nums[i] += prev - curr + 1;
      }
    }
    return count;
  }
};

int main()
{
  Solution s;
  vector<int> nums{3, 2, 1, 2, 1, 7};
  s.minIncrementForUnique(nums);
  return 0;
}