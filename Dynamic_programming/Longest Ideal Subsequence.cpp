#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int longestIdealString(string s, int k)
  {
    int n = s.size();
    vector<int> dp(26, 0);

    int result = 0;

    for (int i = 0; i < n; i++)
    {
      int idx = s[i] - 'a';
      int left = max(0, idx - k);
      int right = min(25, idx + k);

      int longest = 0;
      for (int j = left; j <= right; j++)
      {
        longest = max(longest, dp[j]);
      }
      dp[idx] = max(dp[idx], longest + 1);
      result = max(result, dp[idx]);
    }

    return result;
  }
};

int main()
{
  Solution solution;
  string s = "acfgbd";
  int k = 2;
  solution.longestIdealString(s, k);
  return 0;
}
