#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<vector<int>> result;
  vector<int> combination;

  void solve(int start, int target, int k)
  {
    if (target == 0 && k == 0)
    {
      result.push_back(combination);
      return;
    }

    for (int i = start; i <= 9; i++)
    {
      if (i > target)
        break;
      combination.push_back(i);
      solve(i + 1, target - i, k - 1);
      combination.pop_back();
    }
  }
  vector<vector<int>> combinationSum3(int k, int n)
  {
    solve(1, n, k);
    return result;
  }
};

int main()
{
  Solution solution;
  int k = 3, target = 7;
  solution.combinationSum3(k, target);

  return 0;
}
