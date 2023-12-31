#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int maxLengthBetweenEqualCharacters(string s)
  {
    int n = s.size();
    int result = -1;
    unordered_map<char, int> mp;

    for (int i = 0; i < n; i++)
    {
      if (mp.find(s[i]) != mp.end())
      {
        result = max(result, i - mp[s[i]] - 1);
      }
      else
      {
        mp[s[i]] = i;
      }
    }

    return result;
  }
};

int main()
{
  Solution s;
  s.maxLengthBetweenEqualCharacters("scayofdzca");

  return 0;
}
