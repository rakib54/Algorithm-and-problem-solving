#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minPatches(vector<int> &nums, int n)
  {
    long maxReach = 0;
    int patch = 0;
    int i = 0;
    int size = nums.size();

    while (maxReach < n)
    {
      if (i < size && nums[i] <= maxReach + 1)
      {
        maxReach += nums[i];
        i++;
      }
      else
      {
        // if maxReach = 3, then it become 3 + 4 = 7
        maxReach += maxReach + 1;
        patch++;
      }
    }

    return patch;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{1, 3};
  int n = 6;

  solution.minPatches(nums, n);
  return 0;
}
