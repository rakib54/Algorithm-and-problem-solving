#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool repeatedSubstringPattern(string s)
  {
    int n = s.size();
    for (int i = n / 2; i >= 1; i--)
    {
      if (n % i == 0)
      {
        int times = n / i;

        string pattern = s.substr(0, i);
        string new_string = "";

        while (times--)
        {
          new_string += pattern;
        }
        if (new_string == s)
        {
          return true;
        }
      }
    }
    return false;
  }
};

int main()
{
  Solution solution;
  solution.repeatedSubstringPattern("abcabc");

  return 0;
}