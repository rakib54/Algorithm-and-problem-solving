#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int largestCombination(vector<int> &candidates)
  {
    int n = candidates.size();
    int maxCombination = 0;

    for (int bitPos = 0; bitPos < 32; bitPos++)
    {
      int count = 0;
      for (int &num : candidates)
      {
        // to find bit position set bit(1)
        if ((num & (1 << bitPos)) != 0)
        {
          count++;
        }
      }
      maxCombination = max(maxCombination, count);
    }

    return maxCombination;
  }
};

int main()
{
  Solution s;
  vector<int> candidates{16, 17, 71, 62, 12, 24, 14};
  s.largestCombination(candidates);
  return 0;
}
