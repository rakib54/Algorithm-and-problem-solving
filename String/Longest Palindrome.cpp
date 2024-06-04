#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int longestPalindrome(string s)
  {
    int n = s.size();
    int count = 0;

    unordered_map<char, int> mp;

    for (char &ch : s)
    {
      mp[ch]++;
    }
    int flag = 0;
    for (auto i : mp)
    {
      if (i.second % 2 == 1)
      {
        flag = 1;
        count += i.second - 1;
      }
      if (i.second % 2 == 0)
      {
        count += i.second;
      }
    }

    if (flag == 1)
      return count + 1;

    return count;
  }
};

int main()
{
  Solution s;
  s.longestPalindrome("abccccdd");
  return 0;
}
