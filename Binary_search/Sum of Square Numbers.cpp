#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool judgeSquareSum(int c)
  {
    long long low = 0, high = sqrt(c);

    while (low <= high)
    {
      long long squareSum = (low * low) + (high * high);
      if (squareSum == c)
      {
        return true;
      }
      else if (squareSum < c)
      {
        low--;
      }
      else
      {
        high--;
      }
    }

    return false;
  }
};

int main()
{
  Solution s;
  s.judgeSquareSum(5);
  return 0;
}
