#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
  {
    int n = items.size();
    sort(items.begin(), items.end());

    int maxBeautySeen = 0;
    for (int i = 0; i < n; i++)
    {
      maxBeautySeen = max(maxBeautySeen, items[i][1]);
      items[i][1] = maxBeautySeen;
    }

    int m = queries.size();
    vector<int> maxBeauties(m, 0);

    for (int i = 0; i < m; i++)
    {
      int low = 0, high = n - 1;
      int maxB = 0;

      while (low <= high)
      {
        int mid = low + (high - low) / 2;

        if (queries[i] >= items[mid][0])
        {
          maxB = max(maxB, items[mid][1]);
          low = mid + 1;
        }
        else
        {
          high = mid - 1;
        }
      }
      maxBeauties[i] = maxB;
    }

    return maxBeauties;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> items{{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}};
  vector<int> queries{1, 2, 3, 4, 5, 6};

  s.maximumBeauty(items, queries);

  return 0;
}
