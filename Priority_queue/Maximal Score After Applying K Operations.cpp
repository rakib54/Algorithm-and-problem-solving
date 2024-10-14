#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  long long maxKelements(vector<int> &nums, int k)
  {
    priority_queue<int> pq;
    ll score = 0;

    for (int num : nums)
    {
      pq.push(num);
    }

    while (k--)
    {
      int top = pq.top();
      pq.pop();
      score += top;
      double val = (double)top / 3;
      pq.push(ceil(val));
    }

    return score;
  }
};

int main()
{
  Solution s;
  vector<int> nums{1, 10, 3, 3, 3};
  int k = 3;
  s.maxKelements(nums, k);

  return 0;
}
