#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> sortedSquares(vector<int> &nums)
  {
    for (int i = 0; i < nums.size(); i++)
    {
      nums[i] = nums[i] * nums[i];
    }

    sort(nums.begin(), nums.end());

    return nums;
  }
};
int main()
{
  Solution solution;
  vector<int> nums{-4, -1, 0, 3, 10};
  solution.sortedSquares(nums);
  return 0;
}
