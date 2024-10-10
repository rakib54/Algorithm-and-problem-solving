#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int maxWidthRamp(vector<int> &nums)
  {
    stack<int> st;
    int n = nums.size();

    // big to small
    for (int i = 0; i < n; i++)
    {
      if (st.empty() || nums[st.top()] > nums[i])
      {
        st.push(i);
      }
    }
    int result = 0;

    for (int j = n - 1; j >= 0; j--)
    {
      while (!st.empty() && nums[j] >= nums[st.top()])
      {
        result = max(result, j - st.top());
        st.pop();
      }
    }

    return result;
  }
};

int main()
{
  Solution s;
  vector<int> nums{6, 0, 8, 2, 1, 5};
  s.maxWidthRamp(nums);

  return 0;
}
