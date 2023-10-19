#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool backspaceCompare(string s, string t)
  {
    stack<char> st1, st2;

    for (int i = 0; i < s.size(); i++)
    {
      char c = s[i];

      if (!st1.empty() && c == '#')
      {
        st1.pop();
      }
      else if (st1.empty() && c == '#')
      {
        continue;
      }
      else
      {
        st1.push(c);
      }
    }
    for (int i = 0; i < t.size(); i++)
    {
      char c = t[i];
      if (!st2.empty() && c == '#')
      {
        st2.pop();
      }
      else if (st2.empty() && c == '#')
      {
        continue;
      }
      else
      {
        st2.push(c);
      }
    }

    return st1 == st2;
  }
};

int main()
{
  Solution solution;
  string s = "ab#c", t = "ad#c";
  solution.backspaceCompare(s, t);
  return 0;
}
