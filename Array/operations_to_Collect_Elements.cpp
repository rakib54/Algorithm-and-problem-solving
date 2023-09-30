#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minOperations(vector<int> &nums, int k)
  {
    int count = 0;
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 1; i <= k; i++)
    {
      mp[i] = 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
      if (!mp.empty())
      {
        count++;
      }
      if (mp.find(nums[i]) != mp.end())
      {
        mp.erase(nums[i]);
      }
    }

    return count;
  }
};

int main()
{
  Solution solution;
  int k = 1;
  vector<int> nums{1, 2};
  int ans = solution.minOperations(nums, k);
  cout << ans;
  return 0;
}
