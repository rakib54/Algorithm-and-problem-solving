#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minGroups(vector<vector<int>> &intervals)
  {
    int n = intervals.size();
    priority_queue<int, vector<int>, greater<int>> pq;

    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < n; i++)
    {
      int start = intervals[i][0];
      int end = intervals[i][1];

      if (!pq.empty() && pq.top() < start)
      {
        pq.pop();
      }
      pq.push(end);
    }

    return pq.size();
  }
};

int main()
{
  Solution s;
  vector<vector<int>> intervals{{5, 10}, {6, 8}, {1, 10}, {6, 8}, {2, 3}};
  s.minGroups(intervals);

  return 0;
}
