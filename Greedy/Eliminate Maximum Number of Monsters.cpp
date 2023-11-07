#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int eliminateMaximum(vector<int> &dist, vector<int> &speed)
  {
    vector<int> time;
    for (int i = 0; i < dist.size(); i++)
    {
      double take_time = (double)dist[i] / speed[i];
      int t = ceil(take_time);
      time.push_back(t);
    }

    sort(time.begin(), time.end());

    int count = 1;
    int curr_time = 0;

    for (int i = 1; i < time.size(); i++)
    {
      curr_time++;
      if (curr_time < time[i])
      {
        count++;
      }
      else
        return count;
    }

    return count;
  }
};

int main()
{
  vector<int> dist{1, 1, 2, 3}, speed{1, 1, 1, 1};
  Solution solution;
  solution.eliminateMaximum(dist, speed);
  return 0;
}
