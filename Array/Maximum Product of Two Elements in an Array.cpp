#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.rbegin(), nums.rend());

    int maxP = (nums[0] - 1) * (nums[1] - 1);

    return maxP;
  }
};

int main()
{
  Solution s;
  vector<int> nums{1, 2, 3, 4, 5, 5};
  s.maxProduct(nums);
  return 0;
}
