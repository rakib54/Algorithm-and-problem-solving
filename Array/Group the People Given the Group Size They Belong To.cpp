#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<vector<int>> groupThePeople(vector<int> &groupSizes)
  {
    int n = groupSizes.size();
    vector<vector<int>> result;

    vector<vector<int>> mp(n + 1);

    for (int i = 0; i < groupSizes.size(); i++)
    {
      int L = groupSizes[i];
      mp[L].push_back(i);

      if (mp[L].size() == L)
      {
        result.push_back(mp[L]);
        mp[L] = {};
      }
    }

    return result;
  }
};

int main()
{

  vector<int> groupSizes{3, 3, 3, 3, 3, 1, 3};
  Solution s;
  s.groupThePeople(groupSizes);

  return 0;
}

// problem link: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/?envType=daily-question&envId=2023-09-11