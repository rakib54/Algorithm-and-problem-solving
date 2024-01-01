#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int findContentChildren(vector<int> &g, vector<int> &s)
  {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int n = g.size();
    int m = s.size();

    int count = 0;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
      if (s[j] >= g[i])
      {
        count++;
        i++;
        j++;
      }
      else
      {
        j++;
      }
    }

    return count;
  }
};

int main()
{
  Solution solution;
  vector<int> g{10, 9, 8, 7};
  vector<int> s{5, 6, 7, 8};
  solution.findContentChildren(g, s);

  return 0;
}
