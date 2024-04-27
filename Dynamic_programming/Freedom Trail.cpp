#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int dp[101][101];
  int countSteps(int ringIdx, int i, int n)
  {
    int dist = abs(i - ringIdx);
    int wrapAround = n - dist;

    return min(dist, wrapAround);
  }
  int solve(int ringIdx, int keyIdx, string &ring, string &key)
  {
    if (keyIdx == key.size())
    {
      return 0;
    }
    if (dp[ringIdx][keyIdx] != -1)
    {
      return dp[ringIdx][keyIdx];
    }
    int result = INT_MAX;

    for (int i = 0; i < ring.size(); i++)
    {
      if (ring[i] == key[keyIdx])
      {
        int totalSteps = 1 + countSteps(ringIdx, i, ring.size()) + solve(i, keyIdx + 1, ring, key);
        result = min(result, totalSteps);
      }
    }

    return dp[ringIdx][keyIdx] = result;
  }
  int findRotateSteps(string ring, string key)
  {
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, ring, key);
  }
};
int main()
{
  Solution s;
  string ring = "godding";
  string key = "gd";
  s.findRotateSteps(ring, key);
  return 0;
}
