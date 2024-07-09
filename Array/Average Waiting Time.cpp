#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  double averageWaitingTime(vector<vector<int>> &customers)
  {
    long long Totaltime = 0;
    int n = customers.size();
    long long time = customers[0][0];
    for (int i = 0; i < n; i++)
    {
      long long arrival = customers[i][0];
      long long timeTaken = customers[i][1];

      time = max(time + timeTaken, arrival + timeTaken);
      Totaltime += (time - arrival);
    }

    return (double)Totaltime / (double)n;
  }
};

int main()
{
  vector<vector<int>> customers{{5, 2}, {5, 4}, {10, 3}, {20, 1}};
  Solution solution;
  solution.averageWaitingTime(customers);
  return 0;
}
