#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string kthDistinct(vector<string> &arr, int k)
  {
    unordered_map<string, int> mp;

    for (string &s : arr)
    {
      mp[s]++;
    }

    for (auto str : arr)
    {
      if (mp[str] == 1)
      {
        k--;
        if (k == 0)
        {
          return str;
        }
      }
    }

    return "";
  }
};

int main()
{
  vector<string> arr{"d", "b", "c", "b", "c", "a"};
  Solution s;
  int k = 2;
  s.kthDistinct(arr, k);
  return 0;
}
