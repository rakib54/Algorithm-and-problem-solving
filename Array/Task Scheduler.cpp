#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int leastInterval(vector<char> &tasks, int n)
  {
    vector<int> freq(26, 0);

    for (auto &ch : tasks)
    {
      freq[ch - 'A']++;
    }

    priority_queue<int> pq; // max heap

    for (int i = 0; i < 26; i++)
    {
      if (freq[i] > 0)
      {
        pq.push(freq[i]);
      }
    }

    int time = 0;
    while (!pq.empty())
    {
      vector<int> tmp;

      for (int i = 1; i <= n + 1; i++)
      {
        if (!pq.empty())
        {
          int topFreq = pq.top();
          pq.pop();
          topFreq--;
          tmp.push_back(topFreq);
        }
      }
      for (int &i : tmp)
      { // remaining freq push back to the queue
        if (i > 0)
        {
          pq.push(i);
        }
      }

      if (pq.empty())
      {
        time += tmp.size();
      }
      else
      {
        time += n + 1;
      }
    }

    return time;
  }
};

int main()
{
  Solution s;
  vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B'};
  int n = 2;
  s.leastInterval(tasks, n);
  return 0;
}
