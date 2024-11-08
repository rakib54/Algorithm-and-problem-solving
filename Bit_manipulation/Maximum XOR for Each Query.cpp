#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
  {
    int n = nums.size();
    vector<int> result(n);

    int totalXor = 0;

    // find the total xor
    for (int i = 0; i < n; i++)
    {
      totalXor ^= nums[i];
    }

    // to find flip, first find the mask and having all sets to 1

    int mask = ((1 << maximumBit) - 1);

    for (int i = 0; i < n; i++)
    {
      int k = totalXor ^ mask; // return flipped version which is best k
      result[i] = k;
      totalXor ^= nums[n - i - 1]; // to remove last element, just xor with last element
    }

    return result;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{0, 1, 1, 3};
  int maximumBit = 2;
  solution.getMaximumXor(nums, maximumBit);

  return 0;
}
