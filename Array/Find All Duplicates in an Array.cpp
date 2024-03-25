#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> findDuplicates(vector<int> &nums)
  {
    vector<int> result;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
      int idx = abs(nums[i]) - 1; // -1 for find correct index

      if (nums[idx] < 0)
      { // has seen already
        result.push_back(idx + 1);
      }
      else
      {
        nums[idx] = -nums[idx]; // have not seen yet
      }
    }

    return result;
  }
};

int main()
{
  Solution s;
  vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
  s.findDuplicates(nums);
  return 0;
}
