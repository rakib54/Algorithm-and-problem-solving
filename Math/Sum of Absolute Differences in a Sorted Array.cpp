#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> getSumAbsoluteDifferences(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> prefix(n, 0);
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
      prefix[i] = prefix[i - 1] + nums[i];
    }

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
      int left = i * nums[i] - (i > 0 ? prefix[i - 1] : 0);
      int right = (prefix[n - 1] - prefix[i]) - (n - 1 - i) * nums[i];

      int sum = left + right;
      ans.push_back(sum);
    }

    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums{2, 3, 5};
  s.getSumAbsoluteDifferences(nums);

  return 0;
}
