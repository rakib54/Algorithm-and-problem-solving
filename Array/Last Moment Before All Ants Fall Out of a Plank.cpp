#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int getLastMoment(int n, vector<int> &left, vector<int> &right)
  {
    int result = 0;

    for (auto &x : left)
    {
      result = max(x, result);
    }
    for (auto &x : right)
    {
      result = max(n - x, result);
    }

    return result;
  }
};

int main()
{
  int n = 4;
  vector<int> left{4, 3}, right{0, 1};
  Solution s;
  s.getLastMoment(n, left, right);

  return 0;
}
