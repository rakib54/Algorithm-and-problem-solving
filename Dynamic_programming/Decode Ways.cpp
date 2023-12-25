#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int dp[101];
  int solve(int i, string &s, int &n)
  {
    if (i == n)
    {
      return 1;
    }
    if (s[i] == '0')
    {
      return 0;
    }
    if (dp[i] != -1)
    {
      return dp[i];
    }
    int result = solve(i + 1, s, n);

    if (i + 1 < n)
    {
      if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
      {
        result += solve(i + 2, s, n);
      }
    }

    return dp[i] = result;
  }

  int numDecodings(string s)
  {
    int n = s.size();
    memset(dp, -1, sizeof(dp));
    return solve(0, s, n);
  }
};

int main()
{
  Solution s;
  s.numDecodings("228");

  return 0;
}
