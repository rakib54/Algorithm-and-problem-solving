#include <bits/stdc++.h>
using namespace std;
#define ll long long

// O(N) time and O(1) space
class Solution
{
public:
  int minimumDeletions(string s)
  {
    int count = INT_MAX;
    int n = s.size();

    int right_a_count = 0;
    int left_b_count = 0;

    for (int i = 0; i < n; i++)
    {
      if (s[i] == 'a')
      {
        right_a_count++;
      }
    }

    for (int i = 0; i < n; i++)
    {
      if (s[i] == 'a')
      {
        right_a_count--;
      }
      count = min(count, right_a_count + left_b_count);
      if (s[i] == 'b')
      {
        left_b_count++;
      }
    }

    return count;
  }
};

// O(N) time and O(2N) space
class Solution2
{
public:
  int minimumDeletions(string s)
  {
    int count = INT_MAX;
    int n = s.size();
    vector<int> right_a(n, 0);
    vector<int> left_b(n, 0);
    int right_a_count = 0;
    int left_b_count = 0;

    for (int i = 0; i < n; i++)
    {
      left_b[i] = left_b_count;
      if (s[i] == 'b')
      {
        left_b_count++;
      }
    }
    for (int i = n - 1; i >= 0; i--)
    {
      right_a[i] = right_a_count;
      if (s[i] == 'a')
      {
        right_a_count++;
      }
    }

    for (int i = 0; i < n; i++)
    {
      count = min(count, right_a[i] + left_b[i]);
    }

    return count;
  }
};

// O(N) time and O(N) space
class Solution3
{
public:
  int minimumDeletions(string s)
  {
    int count = INT_MAX;
    int n = s.size();
    vector<int> v(n, 0);

    int right_a_count = 0;
    int left_b_count = 0;

    for (int i = 0; i < n; i++)
    {
      v[i] = left_b_count;
      if (s[i] == 'b')
      {
        left_b_count++;
      }
    }
    for (int i = n - 1; i >= 0; i--)
    {
      v[i] += right_a_count;

      if (s[i] == 'a')
      {
        right_a_count++;
      }
    }

    for (int i = 0; i < n; i++)
    {
      count = min(count, v[i]);
    }

    return count;
  }
};

int main()
{
  Solution solution;
  string s = "aababbab";
  solution.minimumDeletions(s);

  return 0;
}
