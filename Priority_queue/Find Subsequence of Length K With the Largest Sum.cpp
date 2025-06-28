#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> maxSubsequence(vector<int> &nums, int k)
  {
    vector<int> ans;
    int n = nums.size();
    unordered_map<int, int> mp;
    vector<int> index;
    s for (int i = 0; i < n; i++)
    {
      mp[i] = nums[i];
      pq.push({nums[i], i});
    }
    int a = 1;
    while (!pq.empty() && a <= k)
    {
      auto top = pq.top();
      int val = top.first;
      int idx = top.second;
      index.push_back(idx);
      pq.pop();
      a++;
    }

    sort(index.begin(), index.end());

    for (int i = 0; i < index.size(); i++)
    {
      ans.push_back(mp[index[i]]);
    }

    return ans;
  }
};

int main()
{
  vector<int> nums{2, 1, 3, 3};
  int k = 2;
  return 0;
}
