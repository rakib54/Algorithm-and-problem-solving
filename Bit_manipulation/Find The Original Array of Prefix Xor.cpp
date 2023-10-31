#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> findArray(vector<int> &pref)
  {
    int n = pref.size();

    vector<int> result(n, 0);
    result[0] = pref[0];

    for (int i = 1; i < n; i++)
    {
      result[i] = pref[i] ^ pref[i - 1];
    }

    return result;
  }
};

int main()
{
  Solution s;
  vector<int> pref{5, 2, 0, 3, 1};
  s.findArray(pref);

  return 0;
}
