#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> getSneakyNumbers(vector<int> &nums)
  {
    vector<int> dup;
    unordered_map<int, int> mp;

    for (int num : nums)
    {
      mp[num]++;
    }

    for (auto i : mp)
    {
      if (i.second > 1)
      {
        dup.push_back(i.first);
      }
    }

    return dup;
  }
};
int main()
{
  Solution s;
  s.getSneakyNumbers({1, 2, 3, 4, 3, 2, 5, 6, 7, 8, 8});

  return 0;
}
