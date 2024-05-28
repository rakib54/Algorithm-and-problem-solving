#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int equalSubstring(string s, string t, int maxCost)
  {
    int n = s.size();
    int i = 0, j = 0;
    int curr_cost = 0;
    int maxLen = 0;

    while (j < n)
    {
      curr_cost += abs(s[j] - t[j]);

      while (curr_cost > maxCost)
      {
        curr_cost -= abs(s[i] - t[i]);
        i++; // window shrink from left side
      }

      maxLen = max(j - i + 1, maxLen);

      j++;
    }

    return maxLen;
  }
  // time-> O(n) --> every char visits at most twice i and j pointers
};

int main()
{
  Solution solution;
  string s = "abcd";
  string t = "bcdf";
  int maxCost = 3;

  solution.equalSubstring(s, t, maxCost);
  return 0;
}
