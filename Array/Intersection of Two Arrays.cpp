#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
  {
    unordered_map<int, int> mp;
    unordered_set<int> s;

    for (auto num : nums1)
    {
      mp[num]++;
    }

    for (auto num : nums2)
    {
      if (mp.find(num) != mp.end())
      {
        s.insert(num);
      }
    }
    vector<int> result;

    for (auto i : s)
    {
      result.push_back(i);
    }

    return result;
  }
};

int main()
{
  vector<int> nums1{1, 2, 2, 1};
  vector<int> nums2{1, 4, 5};
  Solution s;
  s.intersection(nums1, nums2);
  return 0;
}
