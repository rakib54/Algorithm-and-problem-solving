#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int partition(vector<int> &nums, int l, int r)
  {
    int p = nums[l];
    int i = l + 1;
    int j = r;

    while (i <= j)
    {
      if (nums[i] < p && nums[j] > p)
      { // greater element left side and smaller element right side
        swap(nums[i], nums[j]);
        i++;
        j--;
      }
      if (nums[i] >= p)
      {
        i++;
      }
      if (nums[j] <= p)
      {
        j--;
      }
    }
    swap(nums[l], nums[j]);
    return j; // pivot element is at jth index
  }
  int findKthLargest(vector<int> &nums, int k)
  {
    int n = nums.size();
    int l = 0;
    int r = n - 1;

    int pivot_index = 0;

    while (true)
    {
      pivot_index = partition(nums, l, r);

      if (pivot_index == k - 1)
      { // k-1 is the result while it is array
        break;
      }
      else if (pivot_index > k - 1)
      {
        r = pivot_index - 1;
      }
      else
      {
        l = pivot_index + 1;
      }
    }

    return nums[pivot_index];
  }
};

int main()
{
  Solution solution;
  vector<int> nums{3, 2, 1, 5, 6, 4};
  int k = 2;
  solution.findKthLargest(nums, k);

  return 0;
}