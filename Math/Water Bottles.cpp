#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int numWaterBottles(int numBottles, int numExchange)
  {
    int bottles = numBottles;

    while (numBottles >= numExchange)
    {
      int a = numBottles / numExchange;
      bottles += a;
      numBottles = a + (numBottles % numExchange);
    }

    return bottles;
  }
};

int main()
{
  Solution s;
  s.numWaterBottles(9, 3);
  return 0;
}
