#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int hammingWeight(uint32_t n)
  {
    int count = 0;
    while (n != 0)
    {
      count += n % 2;
      n = n / 2;
    }
    return count;
  }
};

int main()
{
  Solution solution;
  int n = 00000000000000000000000000001011;
  solution.hammingWeight(n);

  return 0;
}
