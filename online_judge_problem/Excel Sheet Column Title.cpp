#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string convertToTitle(int columnNumber)
  {
    string ans = "";

    while (columnNumber > 0)
    {
      columnNumber--;
      int remainder = columnNumber % 26;
      ans += remainder + 'A';
      columnNumber = columnNumber / 26;
    }
    reverse(ans.begin(), ans.end());

    return ans;
  }
};

int main()
{
  Solution solution;
  solution.convertToTitle(128);

  return 0;
}
