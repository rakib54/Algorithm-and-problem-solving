#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string customSortString(string order, string s)
  {
    unordered_map<char, int> mp;

    for (char &ch : s)
    {
      mp[ch]++;
    }
    string result = "";

    for (auto &ch : order)
    {
      if (mp.find(ch) != mp.end())
      {
        result.append(mp[ch], ch);
        mp.erase(ch);
      }
    }

    for (auto &it : mp)
    {
      result.append(it.second, it.first);
    }

    return result;
  }
};

int main()
{
  string order = "cba";
  string s = "adcb";
  Solution solution;
  solution.customSortString(order, s);
  return 0;
}
