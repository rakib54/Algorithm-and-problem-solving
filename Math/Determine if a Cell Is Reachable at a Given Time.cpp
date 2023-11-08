#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
  {
    int hd = abs(sy - fy);
    int vd = abs(sx - fx);
    if (hd == 0 && vd == 0 && t == 1)
    { // corner case
      return false;
    }

    int min_time = max(hd, vd);

    if (t < min_time)
    {
      return false;
    }

    return true;
  }
};

int main()
{
  Solution solution;
  solution.isReachableAtTime(1, 2, 3, 4, 6);

  return 0;
}
