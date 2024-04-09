#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int timeRequiredToBuy(vector<int> &tickets, int k)
  {
    int n = tickets.size();
    int time = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
      q.push({tickets[i], i});
    }

    while (!q.empty())
    {
      auto ticket = q.front();
      q.pop();
      int idx = ticket.second;

      tickets[idx]--;
      time++;

      if (tickets[k] == 0)
      {
        return time;
      }

      if (tickets[idx] > 0)
      {
        q.push({ticket.first - 1, ticket.second});
      }
    }

    return time;
  }
};

int main()
{
  Solution s;
  vector<int> tickets{5, 1, 1, 1};
  s.timeRequiredToBuy(tickets, 0);
  return 0;
}
