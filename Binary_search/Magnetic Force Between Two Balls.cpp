#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool isPossible(int midForce, vector<int> &position, int m)
  {
    int count = 1;
    int j = 0;
    for (int i = 0; i < position.size(); i++)
    {
      if (position[i] - position[j] >= midForce)
      {
        count++;
        j = i;
      }
      if (count == m)
      { // otherwise it goes wrong
        break;
      }
    }
    return count == m;
  }
  int maxDistance(vector<int> &position, int m)
  {
    int n = position.size();
    sort(position.begin(), position.end());

    int low = 1;
    int high = position[n - 1] - position[0];
    int result = 0;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (isPossible(mid, position, m))
      {
        result = mid;
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }

    return result;
  }
};

int main()
{
  Solution s;
  vector<int> position{1, 2, 3, 4, 7};
  int m = 3;
  s.maxDistance(position, m);
  return 0;
}
