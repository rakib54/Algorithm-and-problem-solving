#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  unordered_map<string, vector<string>> adj;
  vector<string> result;
  int totalTickets = 0;

  bool DFS(string fromAirport, vector<string> &path)
  {
    path.push_back(fromAirport);

    if (path.size() == totalTickets + 1)
    {
      result = path;
      return true;
    }

    vector<string> &neighbors = adj[fromAirport];

    for (int i = 0; i < neighbors.size(); i++)
    {
      string toAirport = neighbors[i];

      // remove from the adj list
      neighbors.erase(neighbors.begin() + i);
      if (DFS(toAirport, path))
      {
        return true;
      }
      neighbors.insert(neighbors.begin() + i, toAirport);
    }
    // if no path exists
    path.pop_back();

    return false;
  }
  vector<string> findItinerary(vector<vector<string>> &tickets)
  {
    totalTickets = tickets.size();

    for (auto &t : tickets)
    {
      string u = t[0];
      string v = t[1];
      adj[u].push_back(v);
    }

    // sort for lexical order
    for (auto &i : adj)
    {
      sort(begin(i.second), end(i.second));
    }
    vector<string> path;
    DFS("JFK", path);

    return result;
  }
};

int main()
{

  Solution s;
  vector<vector<string>> tickets{{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
  vector<string> ans = s.findItinerary(tickets);
  for (auto i : ans)
  {
    cout << i << " ";
  }

  return 0;
}
