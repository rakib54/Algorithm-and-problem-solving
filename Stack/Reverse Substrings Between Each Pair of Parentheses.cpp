#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string reverseParentheses(string s)
  {
    stack<char> st;
    string ans;

    for (char &ch : s)
    {
      if (ch != ')')
      {
        st.push(ch);
      }
      else
      {
        string t;
        while (!st.empty() && st.top() != '(')
        {
          t += st.top(); // reverse
          st.pop();
        }
        st.pop(); // remove ( bracket as well

        // push again
        for (char c : t)
        {
          st.push(c);
        }
      }
    }
    while (!st.empty())
    {
      ans += st.top();
      st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main()
{
  Solution solution;
  string s = "(u(love)i)";
  solution.reverseParentheses(s);
  return 0;
}
