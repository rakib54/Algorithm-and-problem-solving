#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int numIdenticalPairs(vector<int> &nums)
  {
    unordered_map<int, int> mp;
    int count = 0;

    for (int num : nums)
    {
      mp[num]++;
    }

    for (auto &pair : mp)
    {
      int n = pair.second;

      count += (n * (n - 1)) / 2;
    }

    return count;
  }
};

int main()
{
  vector<int> nums{1, 1, 1, 1};

  Solution solution;
  solution.numIdenticalPairs(nums); // expected ans = 6 , (n * (n-1))/2;
  return 0;
}
