#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minOperations(string s)
  {
    int n = s.size();
    string alt1, alt2;

    for (int i = 0; i < n; i++)
    {
      if (i % 2 == 0)
      {
        alt1 += "1";
        alt2 += "0";
      }
      else
      {
        alt1 += "0";
        alt2 += "1";
      }
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] != alt1[i])
      {
        ans1++;
      }
      if (s[i] != alt2[i])
      {
        ans2++;
      }
    }

    return min(ans1, ans2);
  }
};

int main()
{
  Solution s;
  s.minOperations("0101001");

  return 0;
}
