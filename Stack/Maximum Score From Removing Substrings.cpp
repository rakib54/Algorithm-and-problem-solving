#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string removeSubStr(string &s, string &matchStr)
  {
    stack<char> st;

    for (char &ch : s)
    {
      if (ch == matchStr[1] && !st.empty() && st.top() == matchStr[0])
      {
        st.pop();
      }
      else
      {
        st.push(ch);
      }
    }
    string tmp;
    while (!st.empty())
    {
      tmp.push_back(st.top());
      st.pop();
    }

    reverse(tmp.begin(), tmp.end());

    return tmp;
  }
  int maximumGain(string s, int x, int y)
  {
    int n = s.size();
    string maxStr = (x > y) ? "ab" : "ba";
    string minStr = (x < y) ? "ab" : "ba";
    int score = 0;

    // first pass -> take maximum points
    string tmp_first = removeSubStr(s, maxStr);
    int L = tmp_first.size();
    int charRemoved = n - L;
    score += (charRemoved / 2) * max(x, y);

    // second pass

    string tmp_second = removeSubStr(tmp_first, minStr);
    charRemoved = L - tmp_second.size();
    score += (charRemoved / 2) * min(x, y);

    return score;
  }
};

int main()
{
  Solution solution;
  solution.maximumGain("cdbcbbaaabab", 4, 5);

  return 0;
}
