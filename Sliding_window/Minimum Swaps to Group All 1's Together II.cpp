#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minSwaps(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> temp(2 * n);

    for (int i = 0; i < 2 * n; i++)
    {
      temp[i] = nums[i % n];
    }
    int totalOnes = 0;

    for (int i = 0; i < n; i++)
    {
      if (nums[i] == 1)
      {
        totalOnes++;
      }
    }

    int i = 0, j = 0;
    int currOnes = 0, maxOnes = 0;

    while (j < 2 * n)
    {
      if (temp[j] == 1)
      {
        currOnes++;
      }
      if (j - i + 1 > totalOnes)
      {
        currOnes -= temp[i];
        i++;
      }
      maxOnes = max(maxOnes, currOnes);
      j++;
    }
    return totalOnes - maxOnes;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{1, 1, 0, 0, 1};
  solution.minSwaps(nums);

  return 0;
}
