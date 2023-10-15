#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int mod = 1e9 + 7;
  int dp[501][501];
  long long solve(int idx, int steps, int len)
  {
    if (steps == 0)
    {
      if (idx == 0)
      { // staying at 0
        return 1;
      }
      return 0;
    }

    if (steps < 0 || idx < 0 || idx >= len)
    {
      return 0;
    }
    if (dp[idx][steps] != -1)
    {
      return dp[idx][steps];
    }
    long long ans = 0;

    ans += solve(idx, steps - 1, len) % mod;     // stay as it is
    ans += solve(idx - 1, steps - 1, len) % mod; // move left
    ans += solve(idx + 1, steps - 1, len) % mod; // move right

    return dp[idx][steps] = ans % mod;
  }
  int numWays(int steps, int arrLen)
  {
    memset(dp, -1, sizeof(dp));
    return solve(0, steps, arrLen);
  }
};

int main()
{
  Solution s;
  int steps = 3, arrLen = 2;
  s.numWays(steps, arrLen);
  return 0;
}
