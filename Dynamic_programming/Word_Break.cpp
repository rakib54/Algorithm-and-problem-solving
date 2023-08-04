#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int n;
  unordered_set<string> st;
  int dp[301];

  bool solve(int idx, string &s)
  {
    if (idx >= n)
    {
      return true;
    }

    if (st.find(s) != st.end())
    {
      return true;
    }

    if (dp[idx] != -1)
    {
      return dp[idx];
    }

    for (int l = 1; l <= n; l++)
    {
      string tmp = s.substr(idx, l);
      if (st.find(tmp) != st.end() && solve(idx + l, s))
      {
        return dp[idx] = true;
      }
    }
    return dp[idx] = false;
  }
  bool wordBreak(string s, vector<string> &wordDict)
  {
    n = s.size();

    memset(dp, -1, sizeof(dp));
    for (auto word : wordDict)
    {
      st.insert(word);
    }
    return solve(0, s);
  }
};

int main()
{
  string s = "leetcode";
  vector<string> wordDict{"leet", "code"};
  Solution sol;
  cout << sol.wordBreak(s, wordDict);
}