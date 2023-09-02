#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int n;
  unordered_set<string> set;
  int dp[51];
  int solve(int idx, string &s)
  {
    if (idx >= n)
    {
      return 0;
    }

    if (dp[idx] != -1)
    {
      return dp[idx];
    }
    string currstring = "";
    int minExtra = n;
    int currExtra = 0;

    for (int i = idx; i < n; i++)
    {
      currstring.push_back(s[i]);

      if (set.find(currstring) == set.end())
      {
        currExtra = currstring.length();
      }
      else
        currExtra = 0;
      int remainingExtra = solve(i + 1, s);

      int total = currExtra + remainingExtra;
      minExtra = min(total, minExtra);
    }

    return dp[idx] = minExtra;
  }

  int minExtraChar(string s, vector<string> &dictionary)
  {
    n = s.size();

    for (auto words : dictionary)
    {
      set.insert(words);
    }
    memset(dp, -1, sizeof(dp));
    return solve(0, s);
  }
};

int main()
{
  Solution solution;
  string s = "leetscode";
  vector<string> dictionary{"leet", "code", "leetcode"};
  solution.minExtraChar(s, dictionary);

  return 0;
}
