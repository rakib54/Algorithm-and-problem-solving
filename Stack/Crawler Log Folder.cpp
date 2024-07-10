#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int minOperations(vector<string> &logs)
  {
    stack<string> s;

    for (string &log : logs)
    {
      if (log == "../")
      {
        if (!s.empty())
        {
          s.pop();
        }
      }
      else if (log == "./")
      {
        continue;
      }
      else
      {
        s.push(log);
      }
    }
    return s.size();
  }
};

class Solution2
{
public:
  int minOperations(vector<string> &logs)
  {
    int depth = 0;

    for (string &log : logs)
    {
      if (log == "../")
      {
        if (depth > 0)
        {
          depth--;
        }
      }
      else if (log == "./")
      {
        continue;
      }
      else
      {
        depth++;
      }
    }
    return depth;
  }
};

int main()
{
  Solution solution;
  vector<string> logs{"d1/", "d2/", "../", "./", "d3/"};
  solution.minOperations(logs);
  return 0;
}
