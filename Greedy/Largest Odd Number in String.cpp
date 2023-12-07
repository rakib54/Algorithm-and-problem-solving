#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string largestOddNumber(string num)
  {
    int n = num.size();

    for (int i = n - 1; i >= 0; i--)
    {
      int firstOdd = num[i] - '0';
      if (firstOdd % 2 != 0)
      {
        return num.substr(0, i + 1);
      }
    }

    return "";
  }
};

int main()
{
  Solution s;
  s.largestOddNumber("112425");

  return 0;
}
