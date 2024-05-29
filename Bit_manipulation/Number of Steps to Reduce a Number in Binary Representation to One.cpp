#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  void addOne(string &s)
  {
    int i = s.size() - 1;

    while (i >= 0 && s[i] != '0')
    {
      s[i] = '0';
      i--;
    }
    if (i < 0)
    {
      s = '1' + s;
    }
    else
    {
      s[i] = '1'; // when we find 0 then make it '1' and return
    }
  }

  int numSteps(string s)
  {
    int steps = 0;

    while (s.length() > 1)
    {
      int n = s.size();
      if (s[n - 1] == '0')
      {
        s.pop_back();
      }
      else
      {
        addOne(s);
      }
      steps++;
    }

    return steps;
  }
};

int main()
{
  Solution solution;
  solution.numSteps("11001");

  return 0;
}
