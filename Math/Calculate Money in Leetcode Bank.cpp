#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int totalMoney(int n)
  {
    int totalWeek = n / 7;
    int result = 0;

    vector<int> money{1, 2, 3, 4, 5, 6, 7};
    int weekMoney = 0;

    while (totalWeek--)
    {
      for (int i = 0; i < 7; i++)
      {
        result += money[i] + weekMoney;
      }
      weekMoney++;
    }

    int remaining_days = n % 7;

    for (int i = 0; i < remaining_days; i++)
    {
      result += money[i] + weekMoney;
    }

    return result;
  }
};

int main()
{
  Solution s;
  s.totalMoney(100);

  return 0;
}
