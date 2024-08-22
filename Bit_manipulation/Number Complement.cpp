#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int findComplement(int num)
  {
    for (long i = 1; i <= num; i *= 2)
    {
      num = num ^ i;
    }

    return num;
  }
};

int main()
{
  Solution solution;
  solution.findComplement(9);
  return 0;
}
