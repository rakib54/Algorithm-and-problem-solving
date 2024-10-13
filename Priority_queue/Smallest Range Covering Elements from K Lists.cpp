#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> smallestRange(vector<vector<int>> &nums)
  {
    int k = nums.size();

    vector<int> result = {-1000000, 1000000};
    int maxElement = INT_MIN;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    for (int i = 0; i < k; i++)
    {
      // value , listIndex , elementIdx
      pq.push({nums[i][0], i, 0});
      maxElement = max(maxElement, nums[i][0]);
    }

    while (!pq.empty())
    {
      vector<int> curr = pq.top();
      pq.pop();

      int minElement = curr[0];
      int listIdx = curr[1];
      int eleIdx = curr[2];

      if (maxElement - minElement < result[1] - result[0])
      {
        result[0] = minElement;
        result[1] = maxElement;
      }

      // update the range
      if (eleIdx + 1 < nums[listIdx].size())
      {
        int nextElement = nums[listIdx][eleIdx + 1];
        pq.push({nextElement, listIdx, eleIdx + 1});
        maxElement = max(maxElement, nextElement);
      }
      else
      {
        break;
      }
    }

    return result;
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> nums{{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
  solution.smallestRange(nums);

  return 0;
}
