#include <bits/stdc++.h>
using namespace std;
#define ll long long

// highest value in the array should have best possible bitwise and
class Solution
{
public:
  int longestSubarray(vector<int> &nums)
  {
    int result = 0;
    int maxValue = -1;
    int streak = 0;

    // maximum value in the array should have maximum possible bitwise AND
    for (int num : nums)
    {
      if (num > maxValue)
      {
        maxValue = num;
        streak = 0;
        result = 0;
      }

      if (num == maxValue)
      {
        streak++;
      }
      else
        streak = 0;

      result = max(result, streak);
    }

    return result;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{1, 2, 3, 3, 2, 2};
  solution.longestSubarray(nums);

  return 0;
}