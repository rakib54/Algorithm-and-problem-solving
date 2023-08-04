#include <bits/stdc++.h>
using namespace std;
#define ll long long

int solve(int n)
{
  if (n == 0 || n == 1)
  {
    return 0;
  }
  vector<bool> prime(n + 1, true);

  int count = 0;
  for (int i = 2; i < n; i++)
  {
    if (prime[i])
    {
      count++;
      for (int j = i; j < n; j += i)
      {
        prime[j] = false;
      }
    }
  }
  return count;
}

int main()
{
  ll test = 1;
  while (test--)
  {
    int n = 10;
    cout << solve(n);
  }
  return 0;
}
