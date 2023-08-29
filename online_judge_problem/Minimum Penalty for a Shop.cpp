#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int bestClosingTime(string customers)
  {
    int n = customers.size();
    vector<int> prefix(n + 1, 0);

    int first = 0;
    for (int i = 0; i < n; i++)
    {
      if (customers[i] == 'Y')
      {
        first++;
      }
    }
    prefix[0] = first;

    for (int i = 1; i <= n; i++)
    {
      if (customers[i - 1] == 'Y')
      {
        prefix[i] = prefix[i - 1] - 1;
      }
      else if (customers[i - 1] == 'N')
      {
        prefix[i] = prefix[i - 1] + 1;
      }
    }

    int min_hour = -1;

    int min_val = *min_element(prefix.begin(), prefix.end());

    for (int i = 0; i <= n; i++)
    {
      if (prefix[i] == min_val)
      {
        min_hour = i;
        break;
      }
    }

    return min_hour;
  }
};

int main()
{
  Solution solution;
  solution.bestClosingTime("YYYN");

  return 0;
}
