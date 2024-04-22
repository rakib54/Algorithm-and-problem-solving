#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  void fillNeighbors(queue<string> &q, string curr, unordered_set<string> &st)
  {
    for (int i = 0; i < 4; i++)
    {
      char ch = curr[i];

      char inc = ch == '9' ? '0' : ch + 1;
      char dec = ch == '0' ? '9' : ch - 1;

      curr[i] = inc;
      if (st.find(curr) == st.end())
      {
        st.insert(curr);
        q.push(curr);
      }
      curr[i] = dec;
      if (st.find(curr) == st.end())
      {
        st.insert(curr);
        q.push(curr);
      }

      curr[i] = ch;
    }
  }

  int openLock(vector<string> &deadends, string target)
  {
    unordered_set<string> st(begin(deadends), end(deadends));

    string start = "0000";

    if (st.find(start) != st.end())
    {
      return -1;
    }

    queue<string> q;
    q.push(start);
    int level = 0;

    while (!q.empty())
    {
      int n = q.size();

      while (n--)
      {
        string curr = q.front();
        q.pop();

        if (curr == target)
        {
          return level;
        }
        fillNeighbors(q, curr, st);
      }
      level++;
    }

    return -1;
  }
};

int main()
{
  Solution solution;
  vector<string> deadends{"0201", "0101", "0102", "1212", "2002"};
  string target = "0202";
  solution.openLock(deadends, target);
  return 0;
}
