#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int specialArray(vector<int> &nums)
  {
    int ans = -1;
    int n = nums.size();

    for (int i = 0; i <= n; i++)
    {
      int count = 0;

      for (int j = 0; j < n; j++)
      {
        if (i <= nums[j])
        {
          count++;
        }
      }
      if (count == i)
      {
        return i;
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums{3, 5};
  s.specialArray(nums);
  return 0;
}
