#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int MAX_WIDTH;
  string findLine(int i, int j, vector<string> &words, int eachwordSpace, int extraSpace)
  {
    string s;
    for (int k = i; k < j; k++)
    {
      s += words[k];

      if (s.length() + eachwordSpace <= MAX_WIDTH)
      {
        for (int l = 0; l < eachwordSpace; l++)
        {
          s += " ";
        }
      }
      if (s.length() + extraSpace < MAX_WIDTH && extraSpace > 0)
      {
        s += " ";
        extraSpace--;
      }
    }
    while (s.length() < MAX_WIDTH)
    {
      s += " ";
    }
    return s;
  }

  vector<string> fullJustify(vector<string> &words, int maxWidth)
  {
    vector<string> ans;
    MAX_WIDTH = maxWidth;
    int i = 0;
    int n = words.size();

    while (i < n)
    {
      int j = i + 1;
      int totalwordLength = words[i].length();
      int space = 0;

      while (j < n && totalwordLength + space + words[j].length() + 1 <= maxWidth)
      {
        space += 1;
        totalwordLength += words[j].length();
        j++;
      }
      cout << space << " ";
      int remainingSpace = maxWidth - totalwordLength;
      int eachwordSpace = space == 0 ? 0 : remainingSpace / space; // equally distribute space between words
      int extraspace = space == 0 ? 0 : remainingSpace % space;

      if (j == n)
      {
        extraspace = 0;
        eachwordSpace = 1;
      }

      // creates line
      string s = findLine(i, j, words, eachwordSpace, extraspace);
      ans.push_back(s);
      i = j;
    }

    return ans;
  }
};

int main()
{
  Solution s;
  vector<string> words{"This", "is", "an", "example", "of", "text", "justification."};
  int maxWidth = 16;
  vector<string> result = s.fullJustify(words, 16);

  return 0;
}
