#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int N, GOAL, K;
  long dp[101][101];
  const int mod = 1e9 + 7;

  long solve(int count_song, int count_unique)
  {
    if (count_song == GOAL)
    {
      if (count_unique == N)
      {
        return dp[count_song][count_unique] = 1;
      }
      return 0;
    }

    if (dp[count_song][count_unique] != -1)
    {
      return dp[count_song][count_unique];
    }
    long result = 0;

    // option 1 (play Unique song)
    if (N > count_unique)
      result += (N - count_unique) * solve(count_song + 1, count_unique + 1);

    // option 2 (replay song)
    if (count_unique > K)
      result += (count_unique - K) * solve(count_song + 1, count_unique);

    return dp[count_song][count_unique] = result % mod;
  }

  int numMusicPlaylists(int n, int goal, int k)
  {
    N = n;
    GOAL = goal;
    K = k;
    memset(dp, -1, sizeof(dp));
    return solve(0, 0);
  }
};

int main()
{
  int n = 3;
  int goal = 3;
  int k = 31;
  Solution solution;
  solution.numMusicPlaylists(n, goal, k);

  return 0;
}