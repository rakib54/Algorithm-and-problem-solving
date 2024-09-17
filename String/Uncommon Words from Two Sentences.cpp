#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<string> uncommonFromSentences(string s1, string s2)
  {
    vector<string> result;

    unordered_map<string, int> mp;
    stringstream ss(s1);
    stringstream ss2(s2);
    string word;

    while (ss >> word)
    {
      mp[word]++;
    }

    while (ss2 >> word)
    {
      mp[word]++;
    }

    for (auto &i : mp)
    {
      if (i.second == 1)
      {
        result.push_back(i.first);
      }
    }

    return result;
  }
};

int main()
{
  Solution s;
  string s1 = "this apple is sweet", s2 = "this apple is sour";
  s.uncommonFromSentences(s1, s2);

  return 0;
}
