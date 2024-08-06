#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minimumPushes(string word)
  {
    vector<int> mp(26, 0);
    for (char &ch : word)
    {
      mp[ch - 'a']++;
    }

    int result = 0;
    sort(begin(mp), end(mp), greater<int>());

    for (int i = 0; i < 26; i++)
    {
      int freq = mp[i];
      int press = i / 8 + 1;

      result += freq * press;
    }

    return result;
  }
};

int main()
{
  Solution s;
  string word = "xyzxyzxyzxyz";
  s.minimumPushes(word);
  return 0;
}
