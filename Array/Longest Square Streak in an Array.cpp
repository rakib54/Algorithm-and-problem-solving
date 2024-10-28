#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int longestSquareStreak(vector<int> &nums)
  {
    unordered_set<long long> st(nums.begin(), nums.end());

    int maxStreak = 0;

    // TC 0(n)
    for (int num : nums)
    {
      int streak = 0;
      long long curr = num;

      // 0(1) because while loop runs maximum 5 times
      while (st.find(curr) != st.end())
      {
        streak++;

        if (curr * curr > 100000)
          break;
        curr = curr * curr;
      }

      maxStreak = max(maxStreak, streak);
    }

    return maxStreak < 2 ? -1 : maxStreak;
  }
};

// recursion solution
class Solution2
{
public:
  int solve(long long curr, unordered_set<long long> &st)
  {
    if (st.find(curr * curr) == st.end())
    {
      return 0;
    }

    return 1 + solve(curr * curr, st);
  }
  int longestSquareStreak(vector<int> &nums)
  {
    int n = nums.size();
    unordered_set<long long> st(nums.begin(), nums.end());

    int maxStreak = 0;

    for (int i = 0; i < n; i++)
    {
      int result = solve(nums[i], st);
      if (result != 0)
      { // including curr nums[i]
        result++;
      }
      maxStreak = max(maxStreak, result);
    }

    return maxStreak == 0 ? -1 : maxStreak;
  }
};

int main()
{
  Solution s;
  vector<int> nums{4, 3, 6, 16, 8, 2};
  s.longestSquareStreak(nums);

  return 0;
}
