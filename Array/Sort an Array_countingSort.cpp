#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> sortArray(vector<int> &nums)
  {
    int min_num = *min_element(nums.begin(), nums.end());
    int max_num = *max_element(nums.begin(), nums.end());
    unordered_map<int, int> mp;
    for (auto &num : nums)
    {
      mp[num]++;
    }

    int i = 0;

    for (int num = min_num; num <= max_num; num++)
    {
      while (mp[num] > 0)
      {
        nums[i] = num;
        i++;
        mp[num]--;
      }
    }
    return nums;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{5, 2, 3, 1};
  solution.sortArray(nums);
  return 0;
}
