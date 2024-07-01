#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool threeConsecutiveOdds(vector<int> &arr)
  {
    int n = arr.size();
    int odds = 0;

    for (int i = 0; i < n; i++)
    {
      if (arr[i] % 2)
      {
        odds++;
      }
      else
      {
        odds = 0;
      }
      if (odds == 3)
        return true;
    }
    return false;
  }
};

int main()
{
  Solution solution;
  vector<int> arr{2, 1, 1, 1};

  solution.threeConsecutiveOdds(arr);
  return 0;
}
