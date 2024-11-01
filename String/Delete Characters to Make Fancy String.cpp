#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string makeFancyString(string s)
  {
    int n = s.size();
    string result;
    result.push_back(s[0]);
    int freq = 1;

    for (int i = 1; i < n; i++)
    {
      if (s[i] == result.back())
      {
        freq++;
      }
      else
      {
        freq = 1;
      }

      if (freq < 3)
      {
        result.push_back(s[i]);
      }
    }
    return result;
  }
};

class Solution2
{
public:
  string makeFancyString(string s)
  {
    int n = s.size();
    string result;
    result.push_back(s[0]);
    int count = 1;

    for (int i = 1; i < n; i++)
    {
      if (s[i] == result.back())
      {
        count++;
        if (count < 3)
        {
          result.push_back(s[i]);
        }
      }
      else
      {
        count = 1;
        result.push_back(s[i]);
      }
    }
    return result;
  }
};

int main()
{
  Solution solution;
  string s = "aaabaaaa";
  solution.makeFancyString(s);

  return 0;
}
