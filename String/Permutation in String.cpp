#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool checkInclusion(string s1, string s2)
  {

    int n = s1.size();
    int m = s2.size();

    if (n > m)
    {
      return false;
    }
    vector<int> freq1(26, 0), freq2(26, 0);

    for (char &ch : s1)
    {
      freq1[ch - 'a']++;
    }

    int i = 0, j = 0;

    while (j < m)
    {
      freq2[s2[j] - 'a']++;

      if (j - i + 1 > n)
      {
        freq2[s2[i] - 'a']--;
        i++;
      }

      if (freq1 == freq2)
      {
        return true;
      }
      j++;
    }

    return false;
  }
};

int main()
{
  Solution solution;
  string s1 = "ab", s2 = "eidbaooo";

  solution.checkInclusion(s1, s2);

  return 0;
}
