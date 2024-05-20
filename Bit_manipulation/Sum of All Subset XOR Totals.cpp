#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int n;
  // backtrack
  void solve(vector<int> &nums, int i, vector<vector<int>> &subsets, vector<int> &v)
  {
    if (i == n)
    {
      subsets.push_back(v);
      return;
    }

    v.push_back(nums[i]);           // do
    solve(nums, i + 1, subsets, v); // explore
    v.pop_back();                   // undo
    solve(nums, i + 1, subsets, v); // explore again
  }

  int subsetXORSum(vector<int> &nums)
  {
    n = nums.size();
    vector<vector<int>> subsets;
    vector<int> v;
    solve(nums, 0, subsets, v);

    int result = 0;
    for (vector<int> &subset : subsets)
    {
      int Xor = 0;
      for (int num : subset)
      {
        Xor ^= num;
      }
      result += Xor;
    }

    return result;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{1, 3};
  solution.subsetXORSum(nums);

  return 0;
}
