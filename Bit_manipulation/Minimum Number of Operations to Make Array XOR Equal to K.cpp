#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minOperations(vector<int> &nums, int k)
  {
    int n = nums.size();
    int xorSum = 0;

    for (int i = 0; i < n; i++)
    {
      xorSum ^= nums[i];
    }

    return __builtin_popcount(xorSum ^ k); // count no of 1's bit
                                           // xorSum^k returns which numbers are different from each other
  }
};

int main()
{
  Solution s;
  vector<int> nums{1, 2, 3, 4};
  int k = 1;
  s.minOperations(nums, k);
  return 0;
}
