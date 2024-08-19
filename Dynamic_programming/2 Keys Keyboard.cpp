#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int dp[1001][1001];
  int solve(int currA, int clipA, int n)
  {
    if (currA == n)
    {
      return 0;
    }
    if (currA > n)
    {
      return 100000;
    }

    if (dp[currA][clipA] != -1)
    {
      return dp[currA][clipA];
    }

    int copyAllAndPaste = 1 + 1 + solve(currA + currA, currA, n);
    int paste = 1 + solve(currA + clipA, clipA, n);

    return dp[currA][clipA] = min(copyAllAndPaste, paste);
  }
  int minSteps(int n)
  {
    if (n == 1)
    {
      return 0;
    }
    memset(dp, -1, sizeof(dp));
    return 1 + solve(1, 1, n);
  }
};

// bottom up

class Solution
{
public:
  int minSteps(int n)
  {
    if (n == 0 || n == 1)
    {
      return 0;
    }
    if (n == 2)
    {
      return 2;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
      int factor = i / 2;

      while (factor >= 1)
      {
        if (i % factor == 0)
        {
          int steps_to_print_factors = dp[factor];
          int copy = 1;
          int paste = (i / factor) - 1;

          dp[i] = steps_to_print_factors + copy + paste;
          break; // because it is the largest factors and it will give the min ans.. greedy approach
        }
        else
        {
          factor--;
        }
      }
    }

    return dp[n];
  }
};

int main()
{
  Solution solution;
  solution.minSteps(27);

  return 0;
}
