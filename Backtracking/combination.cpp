#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> tmp;
vector<vector<int>> ans;

class Solution
{
public:
  void combination(int start, vector<int> &nums, int k, int n)
  {
    if (k == 0)
    {
      ans.push_back(tmp);
      return;
    }
    if (start >= n)
    {
      return;
    }

    tmp.push_back(nums[start]);             // take
    combination(start + 1, nums, k - 1, n); // explore
    tmp.pop_back();                         // remove
    combination(start + 1, nums, k, n);     // again explore
  }
};

void solve()
{
  int n = 4, k = 2;
  vector<int> nums;
  for (int i = 1; i <= n; i++)
  {
    nums.push_back(i);
  }
  Solution s;
  s.combination(0, nums, k, n);

  for (auto i : ans)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}

int main()
{
  ll test = 1;
  while (test--)
  {
    solve();
  }
  return 0;
}
