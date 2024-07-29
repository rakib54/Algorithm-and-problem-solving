#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int numTeams(vector<int> &rating)
  {
    int n = rating.size();
    int ans = 0;

    for (int j = 1; j < n - 1; j++)
    {
      int countLargeLeft = 0;
      int countSmallLeft = 0;
      for (int i = 0; i < j; i++)
      {
        if (rating[i] < rating[j])
        {
          countSmallLeft++;
        }
        else
        {
          countLargeLeft++;
        }
      }
      int countLargeRight = 0;
      int countSmallRight = 0;
      for (int k = j + 1; k < n; k++)
      {
        if (rating[k] < rating[j])
        {
          countSmallRight++;
        }
        else
        {
          countLargeRight++;
        }
      }

      ans += countLargeLeft * countSmallRight;
      ans += countSmallLeft * countLargeRight;
    }

    return ans;
  }
};

int main()
{
  Solution solution;
  vector<int> rating{2, 5, 3, 4, 1};
  solution.numTeams(rating);

  return 0;
}
