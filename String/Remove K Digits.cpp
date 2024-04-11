#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string removeKdigits(string num, int k)
  {
    int n = num.size();
    string result;

    for (int i = 0; i < n; i++)
    {

      while (result.length() > 0 && k > 0 && result.back() > num[i])
      {
        result.pop_back();
        k--;
      }

      if (result.length() > 0 || num[i] != '0')
      { // remove preceding zero
        result.push_back(num[i]);
      }
    }

    while (result.length() > 0 && k > 0)
    {
      result.pop_back();
      k--;
    }

    if (result == "")
    {
      return "0";
    }

    return result;
  }
};

int main()
{
  Solution solution;
  string num = "12002";
  solution.removeKdigits(num, 2);
  return 0;
}
