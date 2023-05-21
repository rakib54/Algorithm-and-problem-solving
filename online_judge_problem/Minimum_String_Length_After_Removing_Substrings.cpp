#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
  string s = "CCCCDDDD";
  // AB -> remove
  // CD -> remove

  stack<char> st;
  for (auto c : s)
  {
    if (st.empty())
    {
      st.push(c);
    }
    else
    {
      if (c == 'B' && st.top() == 'A')
        st.pop();
      else if (c == 'D' && st.top() == 'C')
        st.pop();
      else
        st.push(c);
    }
  }
  cout << st.size();
}

int main()
{
  ll test = 1;
  while (test--)
  {
    solve();
  }
  return 0;
}
