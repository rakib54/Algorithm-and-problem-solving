#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int numberOfMatches(int n)
  {
    int total = 0;

    while (n > 1)
    {
      int match = n / 2;
      total += match;
      if (n % 2 != 0)
      { // if odd
        n = n / 2 + 1;
      }
      else
        n = n / 2;
    }

    return total;
  }
};

int main()
{
  Solution solution;
  solution.numberOfMatches(15);

  return 0;
}
