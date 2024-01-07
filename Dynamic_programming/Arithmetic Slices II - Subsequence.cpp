#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int numberOfArithmeticSlices(vector<int> &nums)
  {
    int n = nums.size();

    unordered_map<long, int> mp[n];
    int result = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        long diff = (long)nums[i] - nums[j];
        auto it = mp[j].find(diff);

        int count_at_j = it == end(mp[j]) ? 0 : it->second;

        mp[i][diff] += count_at_j + 1;

        result += count_at_j;
      }
    }

    return result;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{2, 4, 6, 8, 10};
  solution.numberOfArithmeticSlices(nums);

  return 0;
}
