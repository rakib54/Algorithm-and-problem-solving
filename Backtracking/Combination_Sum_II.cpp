#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int n;
  vector<vector<int>> result;
  vector<int> combination;
  set<vector<int>> st;
  void solve(int idx, vector<int> &candidates, int target)
  {
    if (target == 0)
    {
      result.push_back(combination);
      return;
    }

    for (int i = idx; i < n; i++)
    {
      if (i > idx && candidates[i] == candidates[i - 1])
      {
        continue;
      }
      if (candidates[i] > target)
      {
        break;
      }
      combination.push_back(candidates[i]);
      solve(i + 1, candidates, target - candidates[i]);
      combination.pop_back();
    }
  }
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
  {
    sort(candidates.begin(), candidates.end());
    n = candidates.size();
    solve(0, candidates, target);

    return result;
  }
};

int main()
{
  Solution solution;
  vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
  int target = 8;
  solution.combinationSum2(candidates, target);
  return 0;
}

// solution with no duplicates combination
