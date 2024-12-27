#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int maxScoreSightseeingPair(vector<int> &values)
  {
    int maxScore = 0;
    int n = values.size();
    int maxLeftScore = values[0];

    for (int j = 1; j < n; j++)
    {
      int currRightScore = values[j] - j;

      maxScore = max(maxScore, maxLeftScore + currRightScore);

      // update the maximum left score
      int currLeftScore = values[j] + j;

      maxLeftScore = max(maxLeftScore, currLeftScore);
    }

    return maxScore;
  }
};

int main()
{
  Solution solution;
  vector<int> values{8, 1, 5, 2, 6};

  solution.maxScoreSightseeingPair(values);

  return 0;
}
