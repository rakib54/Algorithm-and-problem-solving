#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int scoreOfString(string s)
  {
    int score = 0;
    int n = s.size();

    for (int i = 0; i < n - 1; i++)
    {
      score += abs(s[i] - s[i + 1]);
    }

    return score;
  }
};

int main()
{
  Solution solution;
  solution.scoreOfString("hello");
  return 0;
}
