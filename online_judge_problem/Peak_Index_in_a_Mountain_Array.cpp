#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int peakIndexInMountainArray(vector<int> &arr)
  {
    int index = 0;
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
      {
        index = mid;
        break;
      }
      else if (arr[mid - 1] < arr[mid])
      {
        low = mid + 1;
      }
      else if (arr[mid] > arr[mid + 1])
      {
        high = mid;
      }
    }
    return index;
  }
};
void solve()
{
  vector<int> arr = {0, 1, 0};
  Solution s;
  cout << s.peakIndexInMountainArray(arr);
}

int main()
{
  ll test = 1;
  while (test--)
  {
    solve();
  }
  return 0;
}
