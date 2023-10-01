#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string reverseWords(string s)
  {
    int n = s.size();
    string ans = "";
    string t;
    for (char ch : s)
    {
      if (ch == ' ')
      {
        int n = t.size();
        for (int i = n - 1; i >= 0; i--)
        {
          ans += t[i];
        }
        ans += ' ';
        t = "";
        continue;
      }
      t.push_back(ch);
    }

    for (int i = n - 1; i >= 0; i--)
    {
      if (s[i] == ' ')
        break;
      ans += s[i];
    }

    return ans;
  }
};

int main()
{
  Solution solution;
  solution.reverseWords("I love Leetcode");

  return 0;
}
