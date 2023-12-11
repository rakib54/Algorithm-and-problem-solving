#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int findSpecialInteger(vector<int> &arr)
  {
    int n = arr.size();

    if (n == 1)
    {
      return arr[0];
    }

    int result = arr[0];
    int count = 1;

    for (int i = 1; i < n; i++)
    {
      if (arr[i] == result)
      {
        count++;
        if (count > n / 4) // 25%
        {
          return result;
        }
      }
      else
      {
        result = arr[i];
        count = 1;
      }
    }

    return 0;
  }
};

int main()
{
  Solution s;
  vector<int> nums{1, 2, 2, 6, 6, 6, 6, 7, 10};
  s.findSpecialInteger(nums);
  return 0;
}
