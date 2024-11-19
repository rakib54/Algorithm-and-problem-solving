#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  long long maximumSubarraySum(vector<int> &nums, int k)
  {
    int n = nums.size();
    long long result = 0;
    long long currWindowSum = 0;

    unordered_set<int> st;

    int j = 0;
    int i = 0;

    while (j < n)
    {
      // check if nums[j] is present or not
      // if present remove until nums[j] is exists
      while (st.count(nums[j]))
      {
        currWindowSum -= nums[i];
        st.erase(nums[i]);
        i++;
      }

      currWindowSum += nums[j];
      st.insert(nums[j]);

      if (j - i + 1 == k)
      {
        result = max(result, currWindowSum);
        currWindowSum -= nums[i];
        st.erase(nums[i]);
        i++;
      }
      j++;
    }

    return result;
  }
};

int main()
{
  Solution s;
  vector<int> nums{1, 5, 4, 2, 9, 9, 9};
  int k = 3;
  s.maximumSubarraySum(nums, k);

  return 0;
}
