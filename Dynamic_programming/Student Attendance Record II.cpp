#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int dp[100001][2][3];
  int mod = 1e9 + 7;
  int solve(int n, int absence, int consecutiveLate)
  {
    if (absence >= 2 || consecutiveLate >= 3)
    {
      return 0;
    }
    if (n == 0)
    {
      return 1;
    }

    if (dp[n][absence][consecutiveLate] != -1)
    {
      return dp[n][absence][consecutiveLate];
    }

    int A = solve(n - 1, absence + 1, 0) % mod;
    int L = solve(n - 1, absence, consecutiveLate + 1) % mod;
    int P = solve(n - 1, absence, 0) % mod;

    return dp[n][absence][consecutiveLate] = ((A + L) % mod + P) % mod;
  }
  int checkRecord(int n)
  {
    memset(dp, -1, sizeof(dp));
    return solve(n, 0, 0);
  }
};

int main()
{
  Solution s;
  s.checkRecord(2);
  return 0;
}
