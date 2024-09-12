#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int countConsistentStrings(string allowed, vector<string> &words)
  {
    int mask = 0;

    for (char &ch : allowed)
    {
      mask |= 1 << (ch - 'a');
    }

    int count = 0;
    for (string word : words)
    {
      bool flag = true;

      for (char &ch : word)
      {
        if ((mask >> (ch - 'a') & 1) == 0)
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
