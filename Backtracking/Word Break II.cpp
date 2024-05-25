#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<string> result;
  unordered_set<string> st;

  void solve(int i, string &s, string currentSentence)
  {
    if (i >= s.size())
    {
      result.push_back(currentSentence);
      return;
    }

    for (int j = i; j < s.size(); j++)
    {
      string word = s.substr(i, j - i + 1);
      if (st.count(word))
      {
        string tmpSentence = currentSentence;
        if (!currentSentence.empty())
        {
          currentSentence += " ";
        }
        currentSentence += word;
        solve(j + 1, s, currentSentence);
        currentSentence = tmpSentence;
      }
    }
  }
  vector<string> wordBreak(string s, vector<string> &wordDict)
  {
    for (string &word : wordDict)
    {
      st.insert(word);
    }

    string currentSentence = "";
    solve(0, s, currentSentence);

    return result;
  }
};

int main()
{
  Solution solution;
  vector<string> wordDict{"cat", "cats", "and", "sand", "dog"};
  string s = "catsanddog";
  solution.wordBreak(s, wordDict);
  return 0;
}
