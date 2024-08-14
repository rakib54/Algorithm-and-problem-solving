#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int smallestDistancePair(vector<int> &nums, int k)
  {
    int n = nums.size();
    int maxVal = *max_element(nums.begin(), nums.end());

    vector<int> distance(maxVal + 1, 0);

    for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        int diff = abs(nums[i] - nums[j]);
        distance[diff]++;
      }
    }

    for (int i = 0; i < distance.size(); i++)
    {
      k -= distance[i];

      if (k <= 0)
      {
        return i;
      }
    }

    return -1;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{1, 6, 1};
  int k = 3;

  solution.smallestDistancePair(nums, k);

  return 0;
}
