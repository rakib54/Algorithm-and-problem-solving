#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dp[101][27][101][101];
class Solution
{
public:
  int solve(string &s, int i, int prev, int freq, int k)
  {
    if (k < 0)
    {
      return INT_MAX;
    }
    if (i >= s.size())
    {
      return 0;
    }
    if (dp[i][prev][freq][k] != -1)
    {
      return dp[i][prev][freq][k];
    }
    int del = solve(s, i + 1, prev, freq, k - 1);

    int keep = 0;
    if (s[i] - 'a' != prev)
    {
      keep = 1 + solve(s, i + 1, s[i] - 'a', 1, k);
    }
    else
    {
      int one_more_addition = 0;
      if (freq == 1 || freq == 9 || freq == 99)
      {
        one_more_addition = 1;
      }
      keep = one_more_addition + solve(s, i + 1, prev, freq + 1, k);
    }

    return dp[i][prev][freq][k] = min(keep, del);
  }
  int getLengthOfOptimalCompression(string s, int k)
  {
    memset(dp, -1, sizeof(dp));
    return solve(s, 0, 26, 0, k);
  }
};

int main()
{
  Solution s;
  s.getLengthOfOptimalCompression("aabbaa", 2);
  return 0;
}
