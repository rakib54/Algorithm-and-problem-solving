#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int arrayPairSum(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int sum = 0;

    for (int i = 0; i < n; i += 2)
    {
      sum += nums[i];
    }

    return sum;
  }
};

int main()
{
  vector<int> nums{6, 2, 6, 5, 1, 2};
  Solution s;
  s.arrayPairSum(nums);

  return 0;
}
