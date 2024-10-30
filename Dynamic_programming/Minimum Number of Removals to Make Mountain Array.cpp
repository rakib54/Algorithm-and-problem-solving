#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minimumMountainRemovals(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> LIS(n, 1);
    vector<int> LDS(n, 1);

    // calculate LIS
    for (int i = 0; i < n; i++)
    {
      for (int j = i - 1; j >= 0; j--)
      {
        if (nums[i] > nums[j])
        {
          LIS[i] = max(LIS[i], LIS[j] + 1);
        }
      }
    }

    // calculate LDS

    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (nums[i] > nums[j])
        {
          LDS[i] = max(LDS[i], LDS[j] + 1);
        }
      }
    }

    int minRemovals = n;

    for (int i = 1; i < n; i++)
    {
      if (LDS[i] > 1 && LIS[i] > 1)
      { // it must be greater than 1 in both sides
        int removeElements = n - LIS[i] - LDS[i] + 1;
        minRemovals = min(minRemovals, removeElements);
      }
    }

    return minRemovals;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{2, 1, 1, 5, 6, 2, 3, 1};

  solution.minimumMountainRemovals(nums);
  return 0;
}
