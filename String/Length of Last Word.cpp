#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int lengthOfLastWord(string s)
  {
    int n = s.size();
    reverse(s.begin(), s.end());

    bool flag = false;
    int count = 0;

    for (char &ch : s)
    {
      if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
      {
        count++;
        flag = true;
      }
      else
      {
        if (flag == true)
        {
          return count;
        }
      }
    }

    return count;
  }
};

int main()
{
  Solution s;
  string str = "   fly me   to   the moon  ";
  s.lengthOfLastWord(str);
  return 0;
}
