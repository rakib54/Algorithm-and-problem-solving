#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool makeEqual(vector<string> &words)
  {
    int n = words.size();
    if (n == 1)
    {
      return true;
    }
    unordered_map<char, int> mp;

    for (auto word : words)
    {
      for (auto &ch : word)
      {
        mp[ch]++;
      }
    }

    for (auto i : mp)
    {
      if (i.second % n != 0)
      {
        return false;
      }
    }
    return true;
  }
};

int main()
{
  Solution s;
  vector<string> arr{"abc", "aabc", "bc"};
  s.makeEqual(arr);

  return 0;
}
