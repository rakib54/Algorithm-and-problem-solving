#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minSwaps(string s)
  {
    int n = s.size();
    stack<char> st;

    for (char &ch : s)
    {
      if (st.empty())
      {
        st.push(ch);
      }
      else
      {
        if (ch == ']' && st.top() == '[')
        {
          st.pop();
        }
        else
        {
          st.push(ch);
        }
      }
    }

    int pair = st.size() / 2;

    return (pair + 1) / 2;
  }
};

int main()
{
  Solution s;
  s.minSwaps("]]][[[");

  return 0;
}
