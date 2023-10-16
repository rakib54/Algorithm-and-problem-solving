#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> getRow(int rowIndex)
  {
    vector<vector<int>> ans;
    for (int i = 0; i < 34; i++) // constrain <= 33
    {
      vector<int> v(i + 1, 1);
      for (int j = 1; j < i; j++)
      {
        v[j] = ans[i - 1][j] + ans[i - 1][j - 1];
      }
      ans.push_back(v);
    }
    return ans[rowIndex];
  }
};

int main()
{
  Solution s;
  s.getRow(3);
  return 0;
}
