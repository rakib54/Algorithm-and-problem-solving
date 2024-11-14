#include <bits/stdc++.h>
using namespace std;
#define ll long long

// TC -> 0(nlogn)
// SC -> 0(1)
// pattern: Binary search on answer
class Solution
{
public:
  int minimizedMaximum(int n, vector<int> &quantities)
  {
    int result = INT_MAX;

    int left = 1, right = *max_element(quantities.begin(), quantities.end());

    // log(maxValue) -> log(n)
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      int total = 0;

      // 0(n)
      for (int ele : quantities)
      {
        total += ele % mid == 0 ? ele / mid : ele / mid + 1;
      }
      int x = n;
      x -= total;

      // ans is valid and try to minimize the answer
      if (x >= 0)
      {
        result = min(result, mid);
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }

    return result;
  }
};

int main()
{
  Solution solution;
  int n = 7;
  vector<int> quantities{15, 10, 10};

  solution.minimizedMaximum(n, quantities);

  return 0;
}
