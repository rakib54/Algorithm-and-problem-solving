#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int concatenatedBinary(int n)
  {
    int digit = 0;
    int MOD = 1e9 + 7;
    long result = 0;

    for (int num = 1; num <= n; num++)
    {
      if ((num & (num - 1)) == 0)
      {
        digit++;
      }

      result = ((result << digit) % MOD + num) % MOD;
    }

    return result;
  }
};

int main()
{
  Solution s;
  cout << s.concatenatedBinary(3) << endl;
  return 0;
}
