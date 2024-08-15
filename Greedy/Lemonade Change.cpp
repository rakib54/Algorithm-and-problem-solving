#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool lemonadeChange(vector<int> &bills)
  {
    int n = bills.size();
    int fives = 0, tens = 0;

    if (bills[0] > 5)
    {
      return false;
    }

    for (int i = 0; i < n; i++)
    {
      if (bills[i] == 5)
      {
        fives++;
      }
      else if (bills[i] == 10)
      {
        if (fives > 0)
        {
          tens++;
          fives--;
        }
        else
        {
          return false;
        }
      }
      else
      {
        if (tens > 0 && fives > 0)
        {
          tens--;
          fives--;
        }
        else if (fives >= 3)
        {
          fives -= 3;
        }
        else
        {
          return false;
        }
      }
    }

    return true;
  }
};

int main()
{
  Solution s;
  vector<int> bills{5, 5, 10, 10, 20};
  s.lemonadeChange(bills);
  return 0;
}
