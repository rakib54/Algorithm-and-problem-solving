#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string largestGoodInteger(string s)
  {
    string result = "";

    for (int i = 0; i < s.size() - 2; i++)
    {
      char ch = s[i];
      char ch2 = s[i + 1];
      char ch3 = s[i + 2];

      if (ch == ch2 && ch2 == ch3)
      {
        result = max(result, string(3, ch));
      }
    }

    return result;
  }
};

int main()
{
  Solution solution;
  solution.largestGoodInteger("6777133339");
  return 0;
}
