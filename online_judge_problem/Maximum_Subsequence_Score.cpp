#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
  vector<int> nums1{1, 3, 3, 2};
  vector<int> nums2{2, 1, 3, 4};
  int k = 3;

  int n = nums1.size();
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++)
  {
    v[i] = {nums2[i], nums1[i]};
  }
  sort(v.begin(), v.end());
  long long ans = 0, sum = 0;

  for (auto i : v)
  {
    // cout<<i.first<<" "<<i.second<<endl;
  }
  priority_queue<int, vector<int>, greater<int>> pq; // acending order
  for (int i = n - 1; i >= 0; i--)
  {
    auto &[x, y] = v[i];
    sum += y;
    pq.push(y);

    if (i < (n - k + 1))
    {
      if (pq.size() > k)
      {
        sum -= pq.top();
        pq.pop();
      }
      ans = max(ans, sum * x);
      // cout << sum * x << " ";
    }
  }
  cout << ans << endl;
}

int main()
{
  ll test = 1;
  while (test--)
  {
    solve();
  }
  return 0;
}
