#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
  {
    unordered_set<string> obs;

    for (auto obstacle : obstacles)
    {
      int x = obstacle[0];
      int y = obstacle[1];

      obs.insert(to_string(x) + "_" + to_string(y));
    }

    int x = 0, y = 0;
    int max_distance = 0;
    pair<int, int> dir = {0, 1}; // pointing to north initially

    for (int i = 0; i < commands.size(); i++)
    {
      if (commands[i] == -2)
      { // left 90 deg
        dir = {-dir.second, dir.first};
      }
      else if (commands[i] == -1)
      { // right 90 deg
        dir = {dir.second, -dir.first};
      }
      else
      {
        for (int step = 0; step < commands[i]; step++)
        {
          int new_x = x + dir.first;
          int new_y = y + dir.second;

          string nextKey = to_string(new_x) + "_" + to_string(new_y);

          if (obs.find(nextKey) != obs.end())
          {
            break;
          }

          x = new_x;
          y = new_y;
        }
      }
      max_distance = max(max_distance, x * x + y * y);
    }

    return max_distance;
  }
};

int main()
{
  Solution solution;
  vector<int> commands{4, -1, 4, -2, 4};
  vector<vector<int>> obstacles{{2, 4}};

  solution.robotSim(commands, obstacles);
  return 0;
}
