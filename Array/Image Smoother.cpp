#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<vector<int>> directions{
      {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
  vector<vector<int>> imageSmoother(vector<vector<int>> &img)
  {
    int m = img.size();
    int n = img[0].size();

    vector<vector<int>> result(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        int sum = 0;
        int neighbour_count = 0;

        for (auto &it : directions)
        {
          int new_i = i + it[0];
          int new_j = j + it[1];

          if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n)
          {
            sum += img[new_i][new_j];
            neighbour_count++;
          }
        }
        result[i][j] = sum / neighbour_count;
      }
    }

    return result;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> img{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  s.imageSmoother(img);

  return 0;
}
