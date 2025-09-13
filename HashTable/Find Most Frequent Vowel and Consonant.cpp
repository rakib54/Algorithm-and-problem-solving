#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int maxFreqSum(string s)
  {
    unordered_map<char, int> freq;
    int vFreq = 0;
    int cFreq = 0;

    for (char &ch : s)
    {
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
      {
        freq[ch]++;
        vFreq = max(vFreq, freq[ch]);
      }
      else
      {
        freq[ch]++;
        cFreq = max(cFreq, freq[ch]);
      }
    }

    return vFreq + cFreq;
  }
};

int main()
{

  Solution s;
  s.maxFreqSum("Success");

  return 0;
}
