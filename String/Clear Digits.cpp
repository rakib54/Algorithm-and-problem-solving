#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string clearDigits(string s)
  {
    int n = s.size();
    string ans = "";

    for (char &ch : s)
    {
      if (ch >= '0' && ch <= '9')
      {
        if (!ans.empty())
        {
          ans.pop_back();
        }
      }
      else
      {
        ans.push_back(ch);
      }
    }

    return ans;
  }
};

int main()
{
  Solution s;
  s.clearDigits("cb34");

  return 0;
}
