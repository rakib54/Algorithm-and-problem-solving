#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  long long findScore(vector<int> &nums)
  {
    int n = nums.size();
    long long ans = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++)
    {
      pq.push({nums[i], i});
    }
    vector<int> visited(n, 0);

    while (!pq.empty())
    {
      pair<int, int> value = pq.top();
      pq.pop();
      int num = value.first;
      int idx = value.second;

      if (visited[idx])
      {
        continue;
      }
      // if not visited
      if (visited[idx] == 0)
      {
        ans += num;
      }
      visited[idx] = 1;

      if (idx - 1 >= 0)
      {
        visited[idx - 1] = 1;
      }
      if (idx + 1 < n)
      {
        visited[idx + 1] = 1;
      }
    }

    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums{2, 1, 3, 4, 5, 2};

  s.findScore(nums);

  return 0;
}
