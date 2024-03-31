#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  long long countSubarrays(vector<int> &nums, int minK, int maxK)
  {
    int n = nums.size();
    int minKIdx = -1, maxKIdx = -1, culpritIdx = -1;

    long long result = 0;

    for (int i = 0; i < n; i++)
    {
      if (nums[i] == minK)
        minKIdx = i;
      if (nums[i] == maxK)
        maxKIdx = i;
      if (nums[i] < minK or nums[i] > maxK)
        culpritIdx = i;

      int smallerIdx = min(minKIdx, maxKIdx);
      int tmpAns = smallerIdx - culpritIdx;

      result += tmpAns <= 0 ? 0 : tmpAns;
    }

    return result;
  }
};

int main()
{
  Solution s;
  vector<int> nums{1, 3, 5, 2, 7, 5};
  int minK = 1, maxK = 5;
  s.countSubarrays(nums, minK, maxK);
  return 0;
}
