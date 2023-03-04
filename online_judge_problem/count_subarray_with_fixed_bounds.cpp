#include <bits/stdc++.h>
using namespace std;

int main(){
  // vector<int>nums{1,3,5,2,7,5};
  vector<int>nums{1,1,1,1};
  int minK = 1, maxK = 1;
  int n = nums.size();
  int lastInvalidElement = -1, lastminIndex = -1, lastmaxIndex = -1;
  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] >= minK && nums[i] <= maxK)
    {
      lastminIndex = (nums[i] == minK) ? i : lastminIndex;
      lastmaxIndex = (nums[i] == maxK) ? i : lastmaxIndex;
      ans += max(0, min(lastminIndex, lastmaxIndex) - lastInvalidElement);
    }
    else
    {
      lastInvalidElement = i;
      lastminIndex = -1;
      lastmaxIndex = -1;
    }
  }
  cout<< ans;

  return 0;
}