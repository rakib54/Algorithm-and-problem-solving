#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int passThePillow(int n, int time)
  {
    int chunk = time / (n - 1);

    if (chunk % 2 == 0)
    { // if even starts with 1
      return 1 + time % (n - 1);
    }

    return n - time % (n - 1); // if odd starts with n
  }
};

int main()
{
  Solution s;
  s.passThePillow(10, 20);
  return 0;
}
