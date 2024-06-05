#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  void fillCount(string word, int count[26])
  {
    for (char &ch : word)
    {
      count[ch - 'a']++;
    }
  }
  vector<string> commonChars(vector<string> &words)
  {
    vector<string> result;
    int n = words.size();
    int count[26] = {0};
    fillCount(words[0], count);

    for (int i = 1; i < n; i++)
    {
      int tmp[26] = {0};
      fillCount(words[i], tmp);

      for (int j = 0; j < 26; j++)
      {
        count[j] = min(count[j], tmp[j]);
      }
    }

    for (int i = 0; i < 26; i++)
    {
      if (count[i] > 0)
      {
        for (int j = 0; j < count[i]; j++)
        {
          result.push_back(string(1, i + 'a'));
        }
      }
    }
    return result;
  }
};

int main()
{
  Solution s;
  vector<string> words{"bella", "label", "roller"};
  s.commonChars(words);
  return 0;
}
