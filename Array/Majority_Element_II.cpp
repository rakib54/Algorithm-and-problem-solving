#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> majorityElement(vector<int> &nums)
  {
    int n = nums.size();
    unordered_map<int, int> mp;
    vector<int> ans;

    for (auto &num : nums)
    {
      mp[num]++;
    }

    for (auto ele : mp)
    {
      if (ele.second > n / 3)
      {
        ans.push_back(ele.first);
      }
    }

    return ans;
  }
};
int main()
{
  Solution s;
  vector<int> nums{1, 3, 3};
  s.majorityElement(nums);
  return 0;
}
