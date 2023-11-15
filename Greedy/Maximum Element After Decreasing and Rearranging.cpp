#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
  {
    int n = arr.size();

    sort(arr.begin(), arr.end());
    if (arr[0] != 1)
    {
      arr[0] = 1;
    }

    for (int i = 1; i < n; i++)
    {
      if (abs(arr[i] - arr[i - 1]) > 1)
      {
        arr[i] = arr[i - 1] + 1;
      }
    }

    return *max_element(arr.begin(), arr.end());
  }
};

int main()
{
  Solution s;
  vector<int> arr{1, 2, 2, 2, 2, 1};
  s.maximumElementAfterDecrementingAndRearranging(arr);
  return 0;
}
