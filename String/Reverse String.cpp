#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  void reverseString(vector<char> &s)
  {
    int n = s.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
      char tmp = s[i];
      s[i] = s[j];
      s[j] = tmp;

      i++;
      j--;
    }
  }
};

int main()
{
  Solution s;
  vector<char> c{'h', 'e', 'l', 'l', 'o'};
  s.reverseString(c);
  return 0;
}
