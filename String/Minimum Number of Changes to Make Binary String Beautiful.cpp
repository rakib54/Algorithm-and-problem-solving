#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minChanges(string s)
  {
    int n = s.size();
    int result = 0;

    for (int i = 0; i < n - 1; i += 2)
    {
      if (s[i] != s[i + 1])
      {
        result++;
      }
    }

    return result;
  }
};

int main()
{
  Solution s;
  s.minChanges("000111");
  return 0;
}
