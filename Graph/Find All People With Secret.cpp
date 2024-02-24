#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  typedef pair<int, int> P;
  vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
  {
    unordered_map<int, vector<P>> adj;

    for (auto &meeting : meetings)
    {
      int p1 = meeting[0];
      int p2 = meeting[1];
      int time = meeting[2];

      adj[p1].push_back({p2, time});
      adj[p2].push_back({p1, time});
    }

    queue<P> q; // { p, knew the secret time}
    q.push({0, 0});
    q.push({firstPerson, 0});

    vector<int> timeToKnowSecret(n, INT_MAX);

    timeToKnowSecret[0] = 0;
    timeToKnowSecret[firstPerson] = 0;

    while (!q.empty())
    {
      auto [person, time] = q.front();
      q.pop();

      for (auto &neighbour : adj[person])
      {
        int next_person = neighbour.first;
        int meet_time = neighbour.second;

        if (meet_time >= time && timeToKnowSecret[next_person] > meet_time)
        {
          timeToKnowSecret[next_person] = meet_time;
          q.push({next_person, meet_time});
        }
      }
    }

    vector<int> result;

    for (int i = 0; i < n; i++)
    {
      if (timeToKnowSecret[i] != INT_MAX)
      {
        result.push_back(i);
      }
    }

    return result;
  }
};

int main()
{
  Solution s;
  int n = 6;
  vector<vector<int>> meetings{{1, 2, 5}, {2, 3, 8}, {1, 5, 10}};
  int firstPerson = 1;

  s.findAllPeople(n, meetings, firstPerson);
  return 0;
}
