#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minCost(string colors, vector<int> &neededTime)
  {
    int n = colors.size();

    int cost = 0;
    int curr = 0, prevMax = 0;

    for (int i = 0; i < n; i++)
    {
      if (i > 0 && colors[i] != colors[i - 1])
      {
        prevMax = 0;
      }
      curr = neededTime[i];
      cost += min(prevMax, curr);
      prevMax = max(prevMax, curr);
    }

    return cost;
  }
};

int main()
{
  Solution s;
  vector<int> neededTime{1, 2, 1, 2, 3};
  string colors = "abaac";
  s.minCost(colors, neededTime);

  return 0;
}
