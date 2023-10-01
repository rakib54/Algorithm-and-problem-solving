#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  long long maximumTripletValue(vector<int> &nums)
  {
    long long max_diff = 0, mn = 0, ans = 0;

    for (auto num : nums)
    {
      ans = max(ans, max_diff * num);
      max_diff = max(max_diff, mn - num);

      mn = max(mn, (long long)num);
    }
    return ans;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{12, 6, 1, 2, 7};
  int res = solution.maximumTripletValue(nums);
  cout << res;
  return 0;
}
