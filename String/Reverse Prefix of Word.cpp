#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string reversePrefix(string word, char ch)
  {
    int idx = word.find(ch);

    reverse(word.begin(), word.begin() + idx + 1);
    return word;
  }
};

class Solution2
{
public:
  string reversePrefix(string word, char ch)
  {
    int idx = -1;

    for (int i = 0; i < word.size(); i++)
    {
      if (word[i] == ch)
      {
        idx = i;
        break;
      }
    }

    int i = 0, j = idx;

    while (i < j)
    {
      char tmp = word[i];
      word[i] = word[j];
      word[j] = tmp;
      i++;
      j--;
    }

    return word;
  }
};

int main()
{
  Solution2 solution;
  solution.reversePrefix("abcdefgh", 'd');
  return 0;
}
