#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int n;
  vector<vector<int>> result;
  vector<int> combination;
  void solve(int idx, vector<int> &candidates, int target)
  {
    if (idx >= n || target < 0)
    {
      return;
    }
    if (target == 0)
    {
      result.push_back(combination);
      return;
    }

    combination.push_back(candidates[idx]);
    solve(idx, candidates, target - candidates[idx]);
    combination.pop_back();
    solve(idx + 1, candidates, target);
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    n = candidates.size();
    solve(0, candidates, target);

    return result;
  }
};

int main()
{

  Solution solution;
  vector<int> candidates{2, 3, 6, 7};
  int target = 7;
  solution.combinationSum(candidates, target);

  return 0;
}
