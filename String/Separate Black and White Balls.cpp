#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  long long minimumSteps(string s)
  {
    int n = s.size();
    long long ans = 0;
    long long black = 0;

    for (int i = 0; i < n; i++)
    {
      if (s[i] == '1')
      {
        black++;
      }
      else
      {
        ans += black;
      }
    }

    return ans;
  }
};

int main()
{
  Solution s;
  string str = "100";

  s.minimumSteps(str);

  return 0;
}
