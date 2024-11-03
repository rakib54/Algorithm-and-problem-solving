#include <bits/stdc++.h>
using namespace std;
#define ll long long

// brute force
class Solution
{
public:
  bool rotateString(string s, string goal)
  {
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
      string t = s;
      string a = t.substr(i + 1, n);

      for (int j = 0; j < i + 1; j++)
      {
        a += s[j];
      }
      if (a == goal)
      {
        return true;
      }
    }

    return false;
  }
};

// optimize solution
class Solution
{
public:
  bool rotateString(string s, string goal)
  {
    if (s.size() != goal.size())
    {
      return false;
    }
    string doubleString = s + s;
    // check if goal is present or not
    return doubleString.find(goal) != -1;
  }
};
int main()
{

  return 0;
}
