#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> missingRolls(vector<int> &rolls, int mean, int n)
  {
    int m = rolls.size();
    int sum = accumulate(rolls.begin(), rolls.end(), 0);

    int totalObservations = m + n;
    int totalVal = totalObservations * mean;

    int missing_total = totalVal - sum;

    if (missing_total < n || missing_total > 6 * n)
    { // impossible case
      return {};
    }

    int avg = missing_total / n;
    int mod = missing_total % n;
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
      if (mod > 0)
      {
        result.push_back(avg + 1);
        mod--;
      }
      else
      {
        result.push_back(avg);
      }
    }

    return result;
  }
};

int main()
{
  Solution solution;
  vector<int> rolls{1, 5, 6};
  int mean = 3;
  int n = 4;
  solution.missingRolls(rolls, mean, n);

  return 0;
}
