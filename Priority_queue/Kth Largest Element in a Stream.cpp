#include <bits/stdc++.h>
using namespace std;
#define ll long long

class KthLargest
{
public:
  priority_queue<int, vector<int>, greater<int>> pq;
  int j;
  KthLargest(int k, vector<int> &nums)
  {
    j = k;
    for (int num : nums)
    {
      pq.push(num);
      if (pq.size() > k)
        pq.pop();
    }
  }

  int add(int val)
  {
    pq.push(val);
    if (pq.size() > j)
      pq.pop();

    return pq.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main()
{
  vector<int> nums{1, 2, 3};
  KthLargest s(2, nums);
  s.add(5);
  s.add(15);
  s.add(25);

  return 0;
}
