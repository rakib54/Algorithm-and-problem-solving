#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
  {
    unordered_map<int, int> mp;
    vector<int> ans;

    for (int num : nums1)
    {
      mp[num]++;
    }

    for (int num : nums2)
    {
      if (mp.find(num) != mp.end())
      {
        ans.push_back(num);
        mp[num]--;
      }
      if (mp[num] == 0)
      {
        mp.erase(num);
      }
    }

    return ans;
  }
};

class Solution2
{
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
  {
    int n1 = nums1.size();
    int n2 = nums2.size();
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> v;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
      if (nums1[i] > nums2[j])
      {
        j++;
      }
      else if (nums1[i] < nums2[j])
      {
        i++;
      }
      else
      {
        v.push_back(nums1[i]);
        i++;
        j++;
      }
    }
    return v;
  }
};

int main()
{
  Solution2 s;
  vector<int> nums1{4, 9, 5};
  vector<int> nums2{9, 4, 9, 8, 4};
  s.intersect(nums1, nums2);

  return 0;
}
