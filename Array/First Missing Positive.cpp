#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int firstMissingPositive(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> flag(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
      if (nums[i] <= 0)
        continue;
      if (nums[i] > n)
        continue;
      flag[nums[i]] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
      if (flag[i] == 0)
      {
        return i;
      }
    }

    return n + 1;
  }
};

int main()
{
  vector<int> nums{3, 4, -1, 1};
  Solution s;
  s.firstMissingPositive(nums);
  return 0;
}
