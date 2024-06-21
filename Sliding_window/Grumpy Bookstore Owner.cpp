#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
  {
    int n = customers.size();
    int maxUnsatisfiedCustomer = 0;
    int unsatisfied = 0;

    for (int i = 0; i < minutes; i++)
    {
      if (grumpy[i] == 1)
      {
        unsatisfied += customers[i];
      }
      maxUnsatisfiedCustomer = max(maxUnsatisfiedCustomer, unsatisfied);
    }

    int i = 0, j = minutes;

    while (j < n)
    {
      if (grumpy[j] == 1)
      {
        unsatisfied += customers[j];
        cout << unsatisfied << " ";
      }
      if (grumpy[i] == 1)
      {
        unsatisfied -= customers[i];
      }

      i++;
      j++;
      maxUnsatisfiedCustomer = max(maxUnsatisfiedCustomer, unsatisfied);
    }

    int satisfiedCustomer = 0;

    for (int i = 0; i < n; i++)
    {
      if (grumpy[i] == 0)
      {
        satisfiedCustomer += customers[i];
      }
    }

    return satisfiedCustomer + maxUnsatisfiedCustomer;
  }
};

int main()
{
  Solution s;
  vector<int> customers{1, 0, 1, 2, 1, 1, 7, 5}, grumpy{0, 1, 0, 1, 0, 1, 0, 1};
  int minutes = 3;
  s.maxSatisfied(customers, grumpy, minutes);
  return 0;
}
