#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  long long countBadPairs(vector<int> &nums)
  {
    int n = nums.size();
    long long count = 0;

    for (int i = 0; i < n; i++)
    {
      nums[i] = nums[i] - i;
    }

    unordered_map<int, int> mp;
    mp[nums[0]] = 1;

    for (int j = 1; j < n; j++)
    {
      int countofNumsj = mp[nums[j]];
      int numsbeforej = j;

      int badpairs = numsbeforej - countofNumsj;

      count += badpairs;

      mp[nums[j]]++;
    }

    return count;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{4, 1, 3, 3};

  solution.countBadPairs(nums);
  return 0;
}
