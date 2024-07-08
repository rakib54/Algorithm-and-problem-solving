#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int findTheWinner(int n, int k)
  {
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
      q.push(i);
    }

    while (q.size() > 1)
    {
      for (int i = 1; i < k; i++)
      {
        int top = q.front();
        q.pop();
        q.push(top);
      }
      q.pop();
    }

    return q.front();
  }
};

// Josephus problem

class Solution
{
public:
  int findTheWinner(int n, int k)
  {
    int winner = 0;

    for (int i = 1; i <= n; i++)
    {
      winner = (winner + k) % i;
    }

    return winner + 1;
  }
};

int main()
{

  Solution s;
  s.findTheWinner(5, 2);

  return 0;
}
