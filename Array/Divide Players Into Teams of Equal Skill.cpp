#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  long long dividePlayers(vector<int> &skill)
  {
    int n = skill.size();

    if (n == 2)
    {
      return skill[0] * skill[1];
    }
    long long result = 0;

    sort(skill.begin(), skill.end());

    int i = 0, j = n - 1;
    unordered_map<int, int> mp;

    while (i <= j)
    {
      int pairs = skill[i] + skill[j];
      result += skill[i] * skill[j];

      mp[pairs]++;

      i++;
      j--;
    }

    if (mp.size() > 1)
    {
      return -1;
    }

    return result;
  }
};

int main()
{
  Solution s;
  vector<int> skill{3, 2, 5, 1, 3, 4};
  s.dividePlayers(skill);
  return 0;
}
