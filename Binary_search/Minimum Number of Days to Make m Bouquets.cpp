#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int makeBouquet(int days, vector<int> &bloomDay, int k)
  {
    int bouquetsCount = 0;
    int consicutive_count = 0;
    for (int i = 0; i < bloomDay.size(); i++)
    {
      if (days >= bloomDay[i])
      {
        consicutive_count++;
      }
      else
      {
        consicutive_count = 0;
      }
      if (consicutive_count == k)
      {
        bouquetsCount++;
        consicutive_count = 0;
      }
    }

    return bouquetsCount;
  }
  int minDays(vector<int> &bloomDay, int m, int k)
  {
    int n = bloomDay.size();
    int low = 0, high = *max_element(bloomDay.begin(), bloomDay.end());

    int minDays = -1;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;

      if (makeBouquet(mid, bloomDay, k) >= m)
      {
        minDays = mid;
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    return minDays;
  }
};

int main()
{
  Solution solution;
  vector<int> bloomDay{1, 10, 3, 10, 2};
  int k = 1, m = 3;
  solution.minDays(bloomDay, m, k);
  return 0;
}
