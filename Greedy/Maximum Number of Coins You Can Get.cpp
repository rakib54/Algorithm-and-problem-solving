#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int maxCoins(vector<int> &piles)
  {
    sort(piles.begin(), piles.end());

    int n = piles.size();
    int ans = 0;
    for (int i = n - 1, j = n - 2, k = 0; i >= k && j >= k && k <= i; i--, j -= 2, k++)
    {
      ans += piles[j];
    }

    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> piles{9, 8, 7, 6, 5, 1, 2, 3, 4};
  s.maxCoins(piles);
  return 0;
}
