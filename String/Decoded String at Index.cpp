#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string decodeAtIndex(string s, int k)
  {
    int n = s.size();

    long long size = 0;

    for (auto &ch : s)
    {
      if (isdigit(ch))
      {
        size = size * (ch - '0');
      }
      else
      {
        size++;
      }
    }

    for (int i = n - 1; i >= 0; i--)
    {
      k = k % size;

      if (k == 0 && isalpha(s[i]))
      {
        return string(1, s[i]);
      }
      if (isalpha(s[i]))
      {
        size = size - 1;
      }
      else
      {
        size = size / (s[i] - '0');
      }
    }
    return "";
  }
};

int main()
{
  Solution solution;
  string s = "leet2code3";
  int k = 10;
  solution.decodeAtIndex(s, k);

  return 0;
}
