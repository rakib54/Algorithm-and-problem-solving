#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minimumDeletions(string s)
  {
    int count = 0;

    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
      char curr = s[i];

      if (!st.empty() && st.top() == 'b' && curr == 'a')
      {
        count++;
        st.pop();
      }
      else
      {
        st.push(curr);
      }
    }
    return count;
  }
};

int main()
{
  Solution solution;
  string s = "aababbab";
  solution.minimumDeletions(s);

  return 0;
}
