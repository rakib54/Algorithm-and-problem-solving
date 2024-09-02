#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int chalkReplacer(vector<int> &chalk, int k)
  {
    int n = chalk.size();
    long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);

    k = k % sum; // remaining chalk after used by full cycle

    for (int i = 0; i < n; i++)
    {
      if (chalk[i] > k)
      {
        return i;
      }
      k -= chalk[i];
    }

    return -1;
  }
};

int main()
{
  Solution solution;
  vector<int> chalk{1, 5, 3};
  int k = 25;

  solution.chalkReplacer(chalk, k);

  return 0;
}
