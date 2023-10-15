#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string shortestBeautifulSubstring(string s, int k)
  {
    int n = s.size();
    string ans;
    int count = 0, j = 0, mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
      if (s[i] == '1')
      {
        count++;
      }
      while (s[j] == '0' || count > k)
      {
        if (s[j] == '1')
        {
          count--;
        }
        j++;
      }
      if (count == k)
      {
        int m = i - j + 1;
        string curr = s.substr(j, m);
        if (m < mini)
        {
          mini = m;
          ans = curr;
        }
        if (m == mini) // if equal then return lexicography minimum
        {
          if (ans > curr)
          {
            ans = curr;
          }
        }
      }
    }

    return ans;
  }
};

int main()
{
  Solution solution;
  string s = "11000111";
  int k = 3;
  solution.shortestBeautifulSubstring(s, k);

  return 0;
}
