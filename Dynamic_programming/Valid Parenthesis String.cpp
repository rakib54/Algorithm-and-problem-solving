#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dp[100][100];
  bool solve(int idx, int open, string &s, int &n)
  {
    if (idx == n)
    {
      return open == 0;
    }
    if (dp[idx][open] != -1)
    {
      return dp[idx][open];
    }
    bool valid = false;
    if (s[idx] == '*')
    {
      valid |= solve(idx + 1, open + 1, s, n);
      valid |= solve(idx + 1, open, s, n);

      if (open > 0)
      {
        valid |= solve(idx + 1, open - 1, s, n);
      }
    }
    else if (s[idx] == '(')
    {
      valid |= solve(idx + 1, open + 1, s, n);
    }
    else if (s[idx] == ')' && open > 0)
    {
      valid |= solve(idx + 1, open - 1, s, n);
    }

    return dp[idx][open] = valid;
  }

  bool checkValidString(string s)
  {
    memset(dp, -1, sizeof(dp));
    int n = s.size();
    return solve(0, 0, s, n);
  }
};

int main()
{
  string s = "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())";
  Solution solution;
  solution.checkValidString(s);
  return 0;
}
