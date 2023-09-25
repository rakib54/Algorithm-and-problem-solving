#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<vector<int>> ans;
  vector<int> temp;
  int n;

  void solve(int idx, vector<int> &nums)
  {
    if (idx >= n)
    {
      ans.push_back(temp);
      return;
    }

    temp.push_back(nums[idx]); // take it
    solve(idx + 1, nums);      // explore
    temp.pop_back();           // remove it
    solve(idx + 1, nums);      // explore again
  }
  vector<vector<int>> subsets(vector<int> &nums)
  {
    n = nums.size();

    solve(0, nums);

    return ans;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{1, 2, 3};
  solution.subsets(nums);

  return 0;
}
