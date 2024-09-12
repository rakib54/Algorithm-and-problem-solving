#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
  int countConsistentStrings(string allowed, vector<string> &words)
  {
    unordered_map<char, int> mp;
    int count = 0;

    for (char &ch : allowed)
    {
      mp[ch]++;
    }

    for (string &word : words)
    {
      bool flag = true;
      for (char &ch : word)
      {
        if (mp.find(ch) == mp.end())
        {
          flag = false;
          break;
        }
      }
      if (flag)
      {
        count++;
      }
    }
    return count;
  }
};

int main()
{
  Solution s;
  string allowed = "ab";
  vector<string> words{{"ad"}, {"bd"}, {"aaab"}, {"baa"}, {"badab"}};

  s.countConsistentStrings(allowed, words);

  return 0;
}
