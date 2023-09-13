#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int candy(vector<int> &ratings)
  {
    int n = ratings.size();
    vector<int> res(n, 1);

    for (int i = 0; i < n - 1; i++)
    {
      if (ratings[i] < ratings[i + 1])
      {
        res[i + 1] = res[i] + 1;
      }
    }
    for (int i = n - 1; i >= 1; i--)
    {
      if (ratings[i - 1] > ratings[i])
      {
        res[i - 1] = max(res[i - 1], res[i] + 1);
      }
    }

    int totalCandy = accumulate(res.begin(), res.end(), 0);

    return totalCandy;
  }
};

int main()
{
  Solution s;
  vector<int> ratings{1, 2, 2, 3, 1};
  s.candy(ratings);
  return 0;
}
