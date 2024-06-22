#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int numberOfSubarrays(vector<int> &nums, int k)
  {
    int n = nums.size();

    int count = 0;
    int ans = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;

    for (int i = 0; i < n; i++)
    {
      if (nums[i] % 2)
      {
        count++;
      }
      if (count >= k)
      {
        if (mp.find(count - k) != mp.end())
        {
          ans += mp[count - k];
        }
      }
      mp[count]++;
    }

    return ans;
  }
};

int main()
{
  vector<int> nums{2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
  int k = 2;
  Solution solution;
  solution.numberOfSubarrays(nums, k);
  return 0;
}