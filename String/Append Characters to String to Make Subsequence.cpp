#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int appendCharacters(string s, string t)
  {
    int i = 0, j = 0;
    int n = s.size();
    int m = t.size();

    while (i < n && j < m)
    {
      if (s[i] == t[j])
      {
        j++;
      }
      i++;
    }

    return m - j; // length of the required char appending to the string
  }
};
int main()
{
  Solution solution;
  solution.appendCharacters("coaching", "coding");
  return 0;
}
