#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool canArrange(vector<int> &arr, int k)
  {
    vector<int> mp(k, 0);

    for (int num : arr)
    {
      int rem = (num % k + k) % k; // handle negetive modulo
      mp[rem]++;
    }

    if (mp[0] % 2 != 0)
    {
      return false;
    }

    for (int rem = 1; rem <= k / 2; rem++)
    {
      int counterHalf = k - rem;

      if (mp[counterHalf] != mp[rem])
      {
        return false;
      }
    }

    return true;
  }
};

int main()
{
  Solution solution;
  vector<int> arr{8, 2, 8, 2};
  int k = 5;
  solution.canArrange(arr, k);

  return 0;
}
