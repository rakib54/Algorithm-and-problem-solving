#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int heightChecker(vector<int> &heights)
  {
    int n = heights.size();
    vector<int> expected(begin(heights), end(heights));
    sort(expected.begin(), expected.end());
    int count = 0;

    for (int i = 0; i < n; i++)
    {
      if (heights[i] != expected[i])
      {
        count++;
      }
    }

    return count;
  }
};

int main()
{
  Solution s;
  vector<int> heights{1, 1, 4, 2, 1, 3};
  s.heightChecker(heights);
  return 0;
}
