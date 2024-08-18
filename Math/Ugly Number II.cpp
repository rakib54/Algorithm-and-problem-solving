#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int nthUglyNumber(int n)
  {
    int t2 = 1, t3 = 1, t5 = 1;

    vector<int> t(n + 1);
    t[1] = 1;

    for (int i = 2; i <= n; i++)
    {
      int second = t[t2] * 2;
      int third = t[t3] * 3;
      int fifth = t[t5] * 5;

      t[i] = min({second, third, fifth});

      if (t[i] == second)
      {
        t2++;
      }
      if (t[i] == third)
      {
        t3++;
      }
      if (t[i] == fifth)
      {
        t5++;
      }
    }

    return t[n];
  }
};

int main()
{
  Solution s;
  s.nthUglyNumber(10);
  return 0;
}
