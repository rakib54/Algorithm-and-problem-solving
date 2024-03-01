#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string maximumOddBinaryNumber(string s)
  {
    sort(s.rbegin(), s.rend());

    int n = s.size();

    for (int i = n - 1; i >= 0; i--)
    {
      if (s[i] == '1')
      {
        swap(s[i], s[n - 1]);
      }
    }

    return s;
  }
};

int main()
{
  Solution solution;
  solution.maximumOddBinaryNumber("001");

  return 0;
}
