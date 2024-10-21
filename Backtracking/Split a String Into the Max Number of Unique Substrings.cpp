#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  void solve(int i, string &s, unordered_set<string> &st, int &maxCount, int currCount)
  {

    // pruning. we can not find a better answer to going forward
    if (currCount + (s.size() - i) <= maxCount)
    {
      return;
    }

    if (i >= s.size())
    {
      maxCount = max(maxCount, currCount);
    }

    for (int j = i; j < s.size(); j++)
    {
      string sub = s.substr(i, j - i + 1);

      if (st.find(sub) == st.end())
      {
        st.insert(sub);                               // DO
        solve(j + 1, s, st, maxCount, currCount + 1); // explore
        st.erase(sub);                                // undo
      }
    }
  }
  int maxUniqueSplit(string s)
  {
    unordered_set<string> st;
    int maxCount = 0, currCount = 0;

    solve(0, s, st, maxCount, currCount);

    return maxCount;
  }
};

int main()
{
  Solution sol;
  string s = "ababccc";
  sol.maxUniqueSplit(s);

  return 0;
}
