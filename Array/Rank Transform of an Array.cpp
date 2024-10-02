#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> arrayRankTransform(vector<int> &arr)
  {
    int n = arr.size();
    if (n == 0)
    {
      return {};
    }
    vector<int> v = arr;
    sort(v.begin(), v.end());
    unordered_map<int, int> mp;

    vector<int> result;
    int rank = 1;

    mp[v[0]] = rank;
    for (int i = 1; i < n; i++)
    {
      if (v[i] == v[i - 1])
      {
        mp[v[i]] = rank;
      }
      else
      {
        rank++;
        mp[v[i]] = rank;
      }
    }

    for (int num : arr)
    {
      int curr = mp[num];
      result.push_back(curr);
    }

    return result;
  }
};

int main()
{
  Solution s;
  vector<int> arr{37, 12, 28, 9, 100, 56, 80, 5, 12};
  s.arrayRankTransform(arr);

  return 0;
}
