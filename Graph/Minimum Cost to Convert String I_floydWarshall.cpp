#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  void floydWarshall(vector<vector<long long>> &adjMatrix, vector<char> &original, vector<char> &changed, vector<int> &cost)
  {

    for (int i = 0; i < original.size(); i++)
    {
      char s = original[i] - 'a';
      char c = changed[i] - 'a';
      adjMatrix[s][c] = min(adjMatrix[s][c], (long long)cost[i]);
    }

    // apply floydWarshall
    for (int k = 0; k < 26; k++)
    { // try to find shortest path via k
      for (int i = 0; i < 26; i++)
      {
        for (int j = 0; j < 26; j++)
        {
          adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
        }
      }
    }
  }

  long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
  {
    vector<vector<long long>> adjMatrix(26, vector<long long>(26, INT_MAX));

    floydWarshall(adjMatrix, original, changed, cost); // update adjMatrix shortest path using floyd warshall

    long long ans = 0;

    for (int i = 0; i < source.size(); i++)
    {
      if (source[i] == target[i])
      {
        continue;
      }
      if (adjMatrix[source[i] - 'a'][target[i] - 'a'] == INT_MAX)
      {
        return -1;
      }

      ans += adjMatrix[source[i] - 'a'][target[i] - 'a'];
    }

    return ans;
  }
};

int main()
{
  string source = "abcd";
  string target = "acbe";
  vector<char> original{'a', 'b', 'c', 'c', 'e', 'd'};
  vector<char> changed{'b', 'c', 'b', 'e', 'b', 'e'};
  vector<int> cost{2, 5, 5, 1, 2, 20};
  Solution solution;
  solution.minimumCost(source, target, original, changed, cost);

  return 0;
}
