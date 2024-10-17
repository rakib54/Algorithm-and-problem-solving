#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int maximumSwap(int num)
  {
    string s = to_string(num);
    int n = s.size();
    vector<int> maxRight(10, -1);

    for (int i = 0; i < n; i++)
    {
      int idx = s[i] - '0';
      maxRight[idx] = i;
    }

    for (int i = 0; i < s.size(); i++)
    {
      int currDigit = s[i] - '0';

      for (int digit = 9; digit > currDigit; digit--)
      {
        if (maxRight[digit] > i)
        { // max value should be in right side
          swap(s[i], s[maxRight[digit]]);
          return stoi(s);
        }
      }
    }
    return num;
  }
};

int main()
{
  Solution s;
  s.maximumSwap(7236);
}
