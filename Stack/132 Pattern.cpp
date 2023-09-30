#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool find132pattern(vector<int> &nums)
  {
    int n = nums.size();
    stack<int> st;
    int third = INT_MIN;

    for (int i = n - 1; i >= 0; i--)
    {
      if (nums[i] < third) // third element is second highest number (i < k)
      {
        return true;
      }
      while (!st.empty() && st.top() < nums[i]) // element that is in the stack are maximum (j should be in the stack)
      {
        third = st.top();
        st.pop();
      }
      st.push(nums[i]);
    }

    return false;
  }
};

int main()
{
  vector<int> nums{1, 2, 5, 4};
  Solution solution;
  solution.find132pattern(nums);
  return 0;
}
