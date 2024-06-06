#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool isNStraightHand(vector<int> &hand, int groupSize)
  {
    int n = hand.size();
    if (n % groupSize != 0)
    {
      return false;
    }
    sort(hand.begin(), hand.end());
    map<int, int> mp;

    for (int num : hand)
    {
      mp[num]++;
    }

    while (!mp.empty())
    {
      int curr = mp.begin()->first;

      for (int i = 0; i < groupSize; i++)
      {
        if (mp.find(curr + i) == mp.end())
        {
          return false;
        }
        else
        {
          if (mp[curr + i] > 1)
          {
            mp[curr + i]--;
          }
          else
          {
            mp.erase(curr + i);
          }
        }
      }
    }

    return true;
  }
};

int main()
{
  Solution s;
  vector<int> hand{1, 2, 3, 6, 2, 3, 4, 7, 8};
  s.isNStraightHand(hand, 3);
  return 0;
}
