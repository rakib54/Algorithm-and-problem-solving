#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int N, M;
  int solve(int i, int j, vector<vector<int>> &dp)
  {
    if (i == M - 1 && j == N - 1)
    {
      return 1;
    }
    if (dp[i][j] != -1)
    {
      return dp[i][j];
    }

    int ans = 0;
    if (i < M)
      ans += solve(i + 1, j, dp);
    if (j < N)
      ans += solve(i, j + 1, dp);

    return dp[i][j] = ans;
  }
  int uniquePaths(int m, int n)
  {
    N = n;
    M = m;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return solve(0, 0, dp);
  }
};

int main()
{

  Solution solution;
  int n = 2, m = 3;
  solution.uniquePaths(m, n);

  return 0;
}

/**
 Combinatorics

 int uniquePaths(int m, int n) {
        long long ans = 1;

        for(int i=1;i <= m - 1; i++){
            ans = ans * (n-1+i)/i;
        }
        return (int) ans;
    }
 */
