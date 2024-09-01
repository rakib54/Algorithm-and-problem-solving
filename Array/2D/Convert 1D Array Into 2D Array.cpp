#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
  {
    int size = original.size();
    if (size != n * m)
    {
      return {};
    }

    vector<vector<int>> result(m, vector<int>(n, 0));

    for (int i = 0; i < size; i++)
    {
      int row = i / n; // i / col
      int col = i % n; // i % col

      result[row][col] = original[i];
    }

    return result;
  }
};

int main()
{
  Solution solution;
  int n = 3, m = 1;
  vector<int> original{1, 2, 3, 4};
  solution.construct2DArray(original, m, n);

  return 0;
}
