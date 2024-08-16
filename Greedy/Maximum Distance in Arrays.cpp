#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int maxDistance(vector<vector<int>> &arrays)
  {
    int n = arrays.size();
    int smallest = arrays[0][0];
    int biggest = arrays[0].back();
    int max_distance = 0;

    for (int i = 1; i < n; i++)
    {
      max_distance = max(max_distance, abs(arrays[i].back() - smallest));
      max_distance = max(max_distance, abs(arrays[i][0] - biggest));

      smallest = min(smallest, arrays[i][0]);
      biggest = max(biggest, arrays[i].back());
    }

    return max_distance;

    return 1;
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> arrays{{1, 2, 3}, {4, 5}, {1, 2, 3}};

  solution.maxDistance(arrays);

  return 0;
}
