#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string sortVowels(string s)
  {
    string vowel;
    for (char &i : s)
    {
      if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' || i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U')
      {
        vowel.push_back(i);
      }
    }
    sort(vowel.begin(), vowel.end());

    int n = vowel.size();
    int start = 0;
    for (int i = 0; i < s.size(); i++)
    {
      if (start < n && s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
      {
        s[i] = vowel[start];
        start++;
      }
    }

    return s;
  }
};

int main()
{
  Solution s;
  s.sortVowels("lEetcOde");

  return 0;
}
