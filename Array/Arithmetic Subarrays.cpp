#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
  {
    vector<bool> ans;
    int m = l.size();

    for (int i = 0; i < m; i++)
    {
      vector<int> ele;
      for (int j = l[i]; j <= r[i]; j++)
      {
        ele.push_back(nums[j]);
      }
      sort(ele.begin(), ele.end());
      int diff = ele[1] - ele[0];

      int flag = 0;
      for (int k = 0; k < ele.size() - 1; k++)
      {
        if ((ele[k + 1] - ele[k]) != diff)
        {
          flag = 1;
        }
      }
      if (flag == 0)
      {
        ans.push_back(true);
      }
      else
      {
        ans.push_back(false);
      }
    }

    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums{4, 6, 5, 9, 3, 7};
  vector<int> l{0, 0, 2};
  vector<int> r{2, 3, 5};
  s.checkArithmeticSubarrays(nums, l, r);
  return 0;
}
