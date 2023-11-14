#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int countPalindromicSubsequence(string s)
  {
    int n = s.size();
    unordered_set<char> letters;

    for (auto ch : s)
    {
      letters.insert(ch);
    }
    int result = 0;
    for (char letter : letters)
    {
      int first_idx = -1;
      int last_idx = -1;

      for (int i = 0; i < n; i++)
      {
        if (letter == s[i])
        {
          if (first_idx == -1)
          {
            first_idx = i;
          }
          last_idx = i;
        }
      }
      unordered_set<char> st;

      for (int i = first_idx + 1; i <= last_idx - 1; i++)
      {
        st.insert(s[i]);
      }
      result += st.size();
    }

    return result;
  }
};

int main()
{
  Solution solution;
  solution.countPalindromicSubsequence("aabca");

  return 0;
}
