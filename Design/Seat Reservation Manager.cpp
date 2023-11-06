#include <bits/stdc++.h>
using namespace std;
#define ll long long

class SeatManager
{
public:
  priority_queue<int, vector<int>, greater<int>> pq; // min_heap
  SeatManager(int n)
  {
    for (int i = 1; i <= n; i++)
    {
      pq.push(i);
    }
  }

  int reserve()
  {
    int val = -1;
    if (!pq.empty())
    {
      val = pq.top();
      pq.pop();
    }
    return val;
  }

  void unreserve(int seatNumber)
  {
    pq.push(seatNumber);
  }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

int main()
{

  return 0;
}
