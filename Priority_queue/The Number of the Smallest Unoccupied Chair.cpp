#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  typedef pair<int, int> P;
  int smallestChair(vector<vector<int>> &times, int targetFriend)
  {
    int n = times.size();

    int targetFriendArrivalTime = times[targetFriend][0];

    priority_queue<P, vector<P>, greater<P>> occupied;   //(departure, chair no)
    priority_queue<int, vector<int>, greater<int>> free; // free chair
    int chair = 0;

    sort(times.begin(), times.end());

    for (int i = 0; i < n; i++)
    {
      int arrival = times[i][0];
      int depart = times[i][1];

      while (!occupied.empty() && occupied.top().first <= arrival)
      {
        free.push(occupied.top().second);
        occupied.pop();
      }

      if (free.empty())
      {
        occupied.push({depart, chair});
        if (arrival == targetFriendArrivalTime)
        {
          return chair;
        }
        chair++;
      }
      else
      {
        int leastChairAvailable = free.top();
        free.pop();

        if (arrival == targetFriendArrivalTime)
        {
          return leastChairAvailable;
        }
        occupied.push({depart, leastChairAvailable});
      }
    }

    return -1;
  }
};

class Solution2
{
public:
  int smallestChair(vector<vector<int>> &times, int targetFriend)
  {
    int n = times.size();

    vector<int> chairs(n, -1);
    int targetFriendArrivalTime = times[targetFriend][0];

    sort(times.begin(), times.end());

    for (vector<int> time : times)
    {
      int arrival = time[0];
      int depart = time[1];

      for (int i = 0; i < n; i++)
      {
        if (chairs[i] <= arrival)
        {                     // chair is empty
          chairs[i] = depart; // assign when he left this chair

          if (arrival == targetFriendArrivalTime)
          {
            return i;
          }
          break;
        }
      }
    }

    return -1;
  }
};

int main()
{
  vector<vector<int>> times{{1, 4}, {2, 3}, {4, 6}};
  int targetFriend = 1;
  Solution solution;
  solution.smallestChair(times, targetFriend);

  return 0;
}