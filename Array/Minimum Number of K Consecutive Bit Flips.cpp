#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minKBitFlips(vector<int> &nums, int k)
  {
    int n = nums.size();
    int flips = 0;

    int flipCountPast = 0;
    vector<bool> isFlipped(n, 0);

    for (int i = 0; i < n; i++)
    {
      if (i >= k && isFlipped[i - k] == true)
      {
        flipCountPast--;
      }

      if (flipCountPast % 2 == nums[i])
      {
        if (i + k > n)
        {
          return -1;
        }
        flipCountPast++;
        flips++;
        isFlipped[i] = true;
      }
    }
    return flips;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{0, 0, 0, 1, 0, 1, 1, 0};
  int k = 3;
  solution.minKBitFlips(nums, k);
  return 0;
}
