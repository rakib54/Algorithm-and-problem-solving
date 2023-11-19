#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int reductionOperations(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int smallest = nums[0];
    int result = 0, count = 0;

    for (int i = 0; i < n - 1; i++)
    {
      if (nums[i] != nums[i + 1])
      { // check if the consecutive element are different then add the count
        count++;
      }
      result += count;
    }

    return result;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{1, 2, 2, 2, 3};
  solution.reductionOperations(nums);
  return 0;
}
