#include <bits/stdc++.h>
using namespace std;
#define ll long long

class MountainArray
{
public:
  int get(int index);
  int length();
};

class Solution
{
public:
  int findPeakIndex(MountainArray &mountainArr, int low, int high)
  {
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      int peak = mountainArr.get(mid);

      if (peak > mountainArr.get(mid + 1) && peak > mountainArr.get(mid - 1))
      {
        return mid;
        break;
      }
      else if (peak < mountainArr.get(mid + 1))
      {
        low = mid + 1;
      }
      else
        high = mid - 1;
    }
    return -1;
  }

  int binary_search(MountainArray &mountainArr, int low, int high, int target)
  {
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      int val = mountainArr.get(mid);

      if (val == target)
      {
        return mid;
      }
      else if (val < target)
      {
        low = mid + 1;
      }
      else
        high = mid - 1;
    }
    return -1;
  }

  int reverse_binary_search(MountainArray &mountainArr, int low, int high, int target)
  {
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      int val = mountainArr.get(mid);

      if (val == target)
      {
        return mid;
      }
      else if (val < target)
      {
        high = mid - 1;
      }
      else
        low = mid + 1;
    }
    return -1;
  }
  int findInMountainArray(int target, MountainArray &mountainArr)
  {
    int n = mountainArr.length();
    int peak_index = findPeakIndex(mountainArr, 0, n - 1);

    // find in 0 to peak_index
    int result = binary_search(mountainArr, 0, peak_index, target);

    if (result != -1)
    {
      return result;
    }

    // peak_index + 1 to n-1
    result = reverse_binary_search(mountainArr, peak_index + 1, n - 1, target);

    return result;
  }
};

int main()
{

  return 0;
}
