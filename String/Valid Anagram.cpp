#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if (s == t)
      return true;
    return false;
  }
};

int main()
{
  Solution s;
  s.isAnagram("leetcode", "lcodeete");

  return 0;
}
