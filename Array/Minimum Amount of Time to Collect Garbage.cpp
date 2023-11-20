#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int garbageCollection(vector<string> &garbage, vector<int> &travel)
  {
    int n = travel.size();
    vector<int> prefix(n, 0);
    prefix[0] = travel[0];

    for (int i = 1; i < n; i++)
    {
      prefix[i] = prefix[i - 1] + travel[i];
    }
    unordered_map<char, int> mp, lastseen;

    for (int i = 0; i < garbage.size(); i++)
    {
      for (auto ch : garbage[i])
      {
        mp[ch]++;
        lastseen[ch] = i;
      }
    }
    int result = 0;
    for (auto ele : lastseen)
    {
      char ch = ele.first;
      int idx = ele.second;

      if (idx == 0)
      {
        result += 0 + mp[ch];
      }
      else
      {
        result += mp[ch] + prefix[idx - 1];
      }
    }

    return result;
  }
};

int main()
{
  Solution s;
  vector<string> garbage{"G", "P", "GP", "GG"};
  vector<int> travel{2, 4, 3};
  s.garbageCollection(garbage, travel);
  return 0;
}
