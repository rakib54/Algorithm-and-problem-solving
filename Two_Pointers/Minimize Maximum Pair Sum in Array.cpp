#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minPairSum(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int i = 0, j = n - 1;
    int ans = 0;

    while (i < j)
    {
      ans = max(ans, nums[i] + nums[j]);
      i++;
      j--;
    }

    return ans;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{3, 5, 4, 2, 4, 6};
  solution.minPairSum(nums);

  return 0;
}
