#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minLength(string s)
  {
    int n = s.size();

    int i = 0; // write
    int j = 1; // read

    while (j < n)
    {
      if (i < 0)
      {
        i++;
        s[i] = s[j];
      }
      else if (s[j] == 'B' && s[i] == 'A')
      {
        i--;
      }
      else if (s[j] == 'D' && s[i] == 'C')
      {
        i--;
      }
      else
      {
        i++;
        s[i] = s[j];
      }
      j++;
    }

    return i + 1;
  }
};

class Solution2
{
public:
  int minLength(string s)
  {
    stack<char> st;

    for (char &ch : s)
    {
      if (st.empty())
      {
        st.push(ch);
      }
      else
      {
        if (ch == 'D' && st.top() == 'C')
        {
          st.pop();
        }
        else if (ch == 'B' && st.top() == 'A')
        {
          st.pop();
        }
        else
        {
          st.push(ch);
        }
      }
    }

    return st.size();
  }
};

int main()
{
  Solution solution;
  solution.minLength("ABFCACDB");
  return 0;
}
