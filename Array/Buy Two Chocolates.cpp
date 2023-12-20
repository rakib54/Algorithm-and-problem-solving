#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int buyChoco(vector<int> &prices, int money)
  {
    int firstChocolate = INT_MAX, secondChocolate = INT_MAX;

    int n = prices.size();

    for (int i = 0; i < n; i++)
    {
      if (prices[i] <= firstChocolate)
      {
        secondChocolate = firstChocolate;
        firstChocolate = prices[i];
      }
      else
      {
        secondChocolate = min(secondChocolate, prices[i]);
      }
    }
    int totalCost = firstChocolate + secondChocolate;

    return (totalCost > money ? money : money - totalCost);
  }
};

int main()
{
  Solution s;
  vector<int> prices{6, 3, 2, 1};
  int money = 12;
  s.buyChoco(prices, money);
  return 0;
}

/**
 class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());

        int chocolatesMoney = prices[0] + prices[1];

        if(chocolatesMoney > money){
            return money;
        }

        return money - chocolatesMoney;
    }
};
 *
 */
