#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<int> result;
    deque<int> dq;

    for (int i = 0; i < k; i++)
    {
      while (!dq.empty() && dq.back() < nums[i])
      {
        dq.pop_back();
      }
      dq.push_back(nums[i]);
    }
    result.push_back(dq.front());

    for (int i = k; i < n; i++)
    {
      if (dq.front() == nums[i - k])
      {
        dq.pop_front();
      }
      while (!dq.empty() && dq.back() < nums[i])
      {
        dq.pop_back();
      }
      dq.push_back(nums[i]);
      result.push_back(dq.front());
    }
    return result;
  }
};

int main()
{
  Solution s;
  vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  vector<int> result = s.maxSlidingWindow(nums, k);

  return 0;
}

// solved with O(N) time complexity