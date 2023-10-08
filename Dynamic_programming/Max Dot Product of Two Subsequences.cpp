#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int dp[501][501][2];
  int solve(int i, int j, int selected, vector<int> &nums1, vector<int> &nums2)
  {
    if (i >= nums1.size() || j >= nums2.size())
    {
      if (selected == 0)
      {
        return -1e9;
      }
      return 0;
    }
    if (dp[i][j][selected] != -1)
    {
      return dp[i][j][selected];
    }

    int skip_i = solve(i + 1, j, selected, nums1, nums2);
    int skip_j = solve(i, j + 1, selected, nums1, nums2);
    int ans = max(skip_i, skip_j);
    ans = max(ans, nums1[i] * nums2[j] + solve(i + 1, j + 1, 1, nums1, nums2));

    return dp[i][j][selected] = ans;
  }

  int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
  {
    int n = nums1.size();
    int m = nums2.size();
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, 0, nums1, nums2);
  }
};

int main()
{
  Solution s;
  vector<int> nums1 = {2, 1, -2, 5};
  vector<int> nums2 = {3, 0, -6};
  s.maxDotProduct(nums1, nums2);
  return 0;
}
