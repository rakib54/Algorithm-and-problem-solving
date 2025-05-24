#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> findWordsContaining(vector<string> &words, char x)
  {
    int n = words.size();

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
      int j = words[i].size();
      string s = words[i];
      bool isPresent = false;

      for (int k = 0; k < j; k++)
      {
        if (s[k] == x)
        {
          isPresent = true;
          break;
        }
      }
      if (isPresent)
      {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
int main()
{
  Solution s;
  vector<string> words{"leet", "code"};
  char x = 'e';
  s.findWordsContaining(words, x);

  return 0;
}
