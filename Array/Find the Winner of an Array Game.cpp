#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int getWinner(vector<int> &arr, int k)
  {
    int n = arr.size();
    int maxEle = *max_element(arr.begin(), arr.end());

    if (k >= n)
    {
      return maxEle;
    }

    int winner = arr[0];
    int winStreak = 0;

    for (int i = 1; i < n; i++)
    {
      if (arr[i] > winner)
      {
        winner = arr[i];
        winStreak = 1;
      }
      else
      {
        winStreak++;
      }

      if (winStreak == k || winner == maxEle)
      {
        return winner;
      }
    }

    return winner;
  }
};

int main()
{
  vector<int> arr{1, 3, 2};
  int k = 10;
  Solution solution;
  solution.getWinner(arr, k);

  return 0;
}
