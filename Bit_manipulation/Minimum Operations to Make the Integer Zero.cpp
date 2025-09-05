#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int makeTheIntegerZero(int num1, int num2)
  {
    int t = 0;

    while (true)
    {
      long long val = (long long)num1 - t * (long long)num2;

      if (val < 0)
      {
        return -1;
      }

      if (__builtin_popcountll(val) <= t && t <= val)
      {
        return t;
      }

      t++;
    }

    return -1;
  }
};

int main()
{

  return 0;
}
