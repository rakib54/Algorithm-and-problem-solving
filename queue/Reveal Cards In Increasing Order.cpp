#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> deckRevealedIncreasing(vector<int> &deck)
  {
    sort(deck.begin(), deck.end());

    int n = deck.size();
    vector<int> result(n, 0);
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
      q.push(i);
    }
    int i = 0;

    while (!q.empty() && i < n)
    {
      int top = q.front();
      q.pop();
      result[top] = deck[i];
      i++;

      if (!q.empty())
      {
        int next = q.front();
        q.pop();
        q.push(next);
      }
    }

    return result;
  }
};

int main()
{
  Solution s;
  vector<int> deck{17, 13, 11, 2, 3, 5, 7};
  s.deckRevealedIncreasing(deck);
  return 0;
}
