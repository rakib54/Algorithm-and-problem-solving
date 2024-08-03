#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool canBeEqual(vector<int> &target, vector<int> &arr)
  {
    unordered_map<int, int> mp;

    for (int num : arr)
    {
      mp[num]++;
    }

    for (int i = 0; i < target.size(); i++)
    {
      if (mp.find(target[i]) == mp.end())
      {
        return false;
      }

      mp[target[i]]--;
      if (mp[target[i]] == 0)
      {
        mp.erase(target[i]);
      }
    }

    return true;
  }
};

int main()
{
  Solution s;
  vector<int> target{1, 2, 3, 4};
  vector<int> nums{4, 3, 1, 2};
  s.canBeEqual(target, nums);

  return 0;
}
