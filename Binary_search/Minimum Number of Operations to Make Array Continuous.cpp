#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minOperations(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<int> s;
    for (int num : nums)
    { // remove duplicates
      s.insert(num);
    }
    vector<int> v;

    for (int i : s)
    {
      v.push_back(i);
    }
    int ans = n;

    for (int i = 0; i < v.size(); i++)
    {
      int left = v[i];
      int right = left + n - 1;

      int j = upper_bound(v.begin(), v.end(), right) - v.begin();
      // cout<<j<<" ";
      int count = j - i;

      ans = min(ans, n - count);
    }

    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums{1, 10, 100, 1000};
  s.minOperations(nums);
  return 0;
}
