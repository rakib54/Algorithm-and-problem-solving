#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> singleNumber(vector<int> &nums)
  {
    vector<int> ans;
    unordered_map<int, int> mp;

    for (int num : nums)
    {
      mp[num]++;
    }

    for (auto i : mp)
    {
      if (i.second == 1)
      {
        ans.push_back(i.first);
      }
    }

    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums{1, 2, 1, 3, 2, 5};
  s.singleNumber(nums);
  return 0;
}
