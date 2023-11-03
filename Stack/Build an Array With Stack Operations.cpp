#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<string> buildArray(vector<int> &target, int n)
  {
    vector<string> result;
    int stream = 1;
    int i = 0;

    while (i < target.size() && stream <= n)
    {
      result.push_back("Push");
      if (target[i] == stream)
      {
        i++;
      }
      else
      {
        result.push_back("Pop");
      }
      stream++;
    }

    return result;
  }
};

int main()
{
  vector<int> target{1, 3};
  int n = 3;

  Solution solution;
  solution.buildArray(target, n);

  return 0;
}
