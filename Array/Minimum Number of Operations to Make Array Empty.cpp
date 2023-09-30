#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minOperations(vector<int> &nums)
  {
    unordered_map<int, int> mp;

    for (auto num : nums)
    {
      mp[num]++;
    }

    int count = 0;

    for (auto i : mp)
    {
      int key = i.first;
      int val = i.second;

      if (val % 3 == 0)
      {
        count += val / 3;
        continue;
      }
      else if (val % 3 != 0 && val > 3)
      {
        int rem = val;
        while (val > 0)
        {
          if (val == 4 || val == 2)
          {
            break;
          }
          val = val - 3;
          count++;
        }
        count += val / 2;
      }

      else if (val % 2 == 0)
      {
        count += val / 2;
      }
      else
      {
        return -1;
      }
    }

    return count;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{2, 3, 3, 2, 2, 4, 2, 3, 4};
  solution.minOperations(nums);

  return 0;
}
