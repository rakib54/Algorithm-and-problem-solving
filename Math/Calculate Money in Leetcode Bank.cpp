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

class Solution2
{
public:
  int totalMoney(int n)
  {
    int total = 0;
    int i = 1;
    int day = 0;
    int j = 1;
    while (n--)
    {

      if (day == 7)
      {
        i = j + 1;
        day = 0;
        j++;
      }
      total += i;
      i++;
      day++;
    }

    return total;
  }
};

int main()
{
  Solution s;
  s.totalMoney(100);

  return 0;
}
