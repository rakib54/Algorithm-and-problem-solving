#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int n;
  int dp[301][11];
  int solve(int idx, vector<int> &jobDifficulty, int d)
  {
    if (d == 1)
    {
      int maxD = jobDifficulty[idx];
      for (int i = idx; i < n; i++)
      {
        maxD = max(maxD, jobDifficulty[i]);
      }
      return maxD;
    }
    if (dp[idx][d] != -1)
    {
      return dp[idx][d];
    }

    int finalResult = INT_MAX;
    int maxD = jobDifficulty[idx];

    for (int i = idx; i <= n - d; i++)
    {
      maxD = max(maxD, jobDifficulty[i]);
      int result = maxD + solve(i + 1, jobDifficulty, d - 1);
      finalResult = min(finalResult, result);
    }

    return dp[idx][d] = finalResult;
  }
  int minDifficulty(vector<int> &jobDifficulty, int d)
  {
    n = jobDifficulty.size();
    if (n < d)
    {
      return -1;
    }
    memset(dp, -1, sizeof(dp));
    return solve(0, jobDifficulty, d);
  }
};

int main()
{
  Solution s;
  vector<int> jobDifficulty{6, 5, 4, 3, 2, 1};
  int d = 2;
  s.minDifficulty(jobDifficulty, d);

  return 0;
}
