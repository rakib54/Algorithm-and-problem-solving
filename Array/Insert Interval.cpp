#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
  {
    vector<vector<int>> result;
    int n = intervals.size();

    int i = 0;

    while (i < n)
    {
      if (intervals[i][1] < newInterval[0])
      { // intervals end position is less than new intervals start position then push the current intervals
        result.push_back(intervals[i]);
      }
      else if (intervals[i][0] > newInterval[1])
      { // intervals start position is greater than new intervals end position
        break;
      }
      else
      { // merge interval
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
      }
      i++;
    }
    result.push_back(newInterval);
    while (i < n)
    {
      result.push_back(intervals[i]);
      i++;
    }

    return result;
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> intervals{{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  vector<int> newInterval{4, 7};
  solution.insert(intervals, newInterval);
  return 0;
}
