#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int n;
  int dp[50001];

  int findNextIndex(vector<vector<int>> &array, int start, int currJobEnd)
  {
    int end = n - 1;
    int result = n + 1;
    while (start <= end)
    {
      int mid = start + (end - start) / 2;

      if (array[mid][0] >= currJobEnd)
      {
        result = mid;
        end = mid - 1;
      }
      else
      {
        start = mid + 1;
      }
    }

    return result;
  }

  int solve(vector<vector<int>> &array, int i)
  {
    if (i >= n)
    {
      return 0;
    }
    if (dp[i] != -1)
    {
      return dp[i];
    }
    int next = findNextIndex(array, i + 1, array[i][1]);

    int take = array[i][2] + solve(array, next);
    int not_take = solve(array, i + 1);

    return dp[i] = max(take, not_take);
  }

  int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
  {
    n = startTime.size();
    memset(dp, -1, sizeof(dp));
    vector<vector<int>> array(n, vector<int>(3, 0));

    for (int i = 0; i < n; i++)
    {
      array[i][0] = startTime[i];
      array[i][1] = endTime[i];
      array[i][2] = profit[i];
    }
    auto cmp = [&](auto &vec1, auto &vec2)
    {
      return vec1[0] <= vec2[0];
    };

    sort(array.begin(), array.end(), cmp);

    return solve(array, 0);
  }
};

int main()
{
  Solution s;
  vector<int> start{1, 2, 3, 3};
  vector<int> end{3, 4, 5, 6};
  vector<int> profit{50, 10, 40, 70};
  s.jobScheduling(start, end, profit);
  return 0;
}
