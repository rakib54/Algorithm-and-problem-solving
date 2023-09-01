#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> countBits(int n)
  {
    vector<int> ans(n + 1);
    ans[0] = 0; // 0 has 0 number of 1 bits

    for (int i = 1; i <= n; i++)
    {
      if (i % 2 != 0)
      {
        ans[i] = ans[i / 2] + 1;
      }
      else
      {
        ans[i] = ans[i / 2];
      }
    }
    return ans;
  }
};

int main()
{
  Solution solution;
  vector<int> ans = solution.countBits(5);

  for (auto i : ans)
  {
    cout << i << " ";
  }

  return 0;
}
