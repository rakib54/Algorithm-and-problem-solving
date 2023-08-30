#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  long long minimumReplacement(vector<int> &nums)
  {
    int n = nums.size();

    long long operations = 0;

    for (int i = n - 2; i >= 0; i--)
    {
      if (nums[i] <= nums[i + 1])
      {
        continue;
      }
      // if not increasing
      int parts = nums[i] / nums[i + 1];

      if (nums[i] % nums[i + 1] != 0)
      {
        parts++;
      }
      operations += parts - 1;

      nums[i] = nums[i] / parts;
    }

    return operations;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{3, 9, 3};
  solution.minimumReplacement(nums);

  return 0;
}

// Greedy Approach