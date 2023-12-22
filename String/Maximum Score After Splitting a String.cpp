#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int sumOfzeros(string s)
  {
    if (s.size() == 0)
      return 0;
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
      if ((s[i] - '0') == 0)
      {
        count++;
      }
    }
    return count;
  }
  int sumOfones(string s)
  {
    if (s.size() == 0)
      return 0;
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
      if ((s[i] - '0') == 1)
      {
        count++;
      }
    }
    return count;
  }
  int maxScore(string s)
  {
    int n = s.size();
    int sum = 0;

    for (int i = 0; i < n - 1; i++)
    { // n-1 because it says non empty string
      string left = s.substr(0, i + 1);
      string right = s.substr(i + 1, n - i - 1);

      int leftsum = sumOfzeros(left);
      int rightsum = sumOfones(right);

      sum = max(sum, leftsum + rightsum);
    }

    return sum;
  }
};

int main()
{
  Solution s;
  s.maxScore("0010111");

  return 0;
}
