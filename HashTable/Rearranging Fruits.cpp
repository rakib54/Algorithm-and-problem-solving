#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  long long minCost(vector<int> &basket1, vector<int> &basket2)
  {
    int minEl = INT_MAX;
    unordered_map<int, int> mp;

    // calculate the difference frequency
    for (int &i : basket1)
    {
      mp[i]++;
      minEl = min(minEl, i);
    }

    for (int &i : basket2)
    {
      mp[i]--;
      minEl = min(minEl, i);
    }

    vector<int> finalList;
    for (auto &it : mp)
    {
      int cost = it.first;
      int count = it.second;

      if (count == 0)
      {
        continue;
      }

      // impossible case
      if (count % 2 != 0)
      {
        return -1;
      }

      for (int i = 1; i <= abs(count) / 2; i++)
      {
        finalList.push_back(cost);
      }
    }

    sort(finalList.begin(), finalList.end());
    long long result = 0;
    for (int i = 0; i < finalList.size() / 2; i++)
    {
      result += min(finalList[i], minEl * 2);
    }

    return result;
  }
};

int main()
{

  return 0;
}
