#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  long long countFairPairs(vector<int> &nums, int lower, int upper)
  {
    int n = nums.size();

    long long ans = 0;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 1; i++)
    {
      int x = lower - nums[i], y = upper - nums[i];
      int l_it = lower_bound(nums.begin() + i + 1, nums.end(), x) - begin(nums);
      int u_it = upper_bound(nums.begin() + i + 1, nums.end(), y) - begin(nums);

      cout << l_it << "  " << u_it << endl;

      ans += u_it - l_it;
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums{0, 1, 7, 4, 4, 5};
  int lower = 3;
  int upper = 3;

  s.countFairPairs(nums, lower, upper);
  return 0;
}
