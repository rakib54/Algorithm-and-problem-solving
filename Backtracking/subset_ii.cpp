#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<vector<int>> ans;
  vector<int> temp;
  set<vector<int>> st;
  int n;

  void solve(int idx, vector<int> &nums)
  {
    if (idx >= n)
    {
      st.insert(temp);
      return;
    }
    temp.push_back(nums[idx]); // take it
    solve(idx + 1, nums);      // explore
    temp.pop_back();           // remove it
    solve(idx + 1, nums);      // explore again
  }
  vector<vector<int>> subsetsWithDup(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    n = nums.size();

    solve(0, nums);

    for (auto &it : st)
    {
      ans.push_back(it);
    }

    return ans;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{1, 2, 2};
  solution.subsetsWithDup(nums);

  return 0;
}
