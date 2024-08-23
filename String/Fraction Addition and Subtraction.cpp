#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string fractionAddition(string expression)
  {
    int nume = 0;
    int deno = 1;

    int i = 0;
    int n = expression.size();

    while (i < n)
    {
      int currNume = 0;
      int currDeno = 0;

      bool isNeg = (expression[i] == '-');

      if (expression[i] == '+' || expression[i] == '-')
      {
        i++;
      }

      // build curr numerator
      while (i < n && isdigit(expression[i]))
      {
        int val = expression[i] - '0';
        currNume = (currNume * 10) + val;
        i++;
      }

      i++; // skipping divisor char /

      if (isNeg == true)
      {
        currNume *= -1;
      }

      // build the curr deno
      while (i < n && isdigit(expression[i]))
      {
        int val = expression[i] - '0';
        currDeno = (currDeno * 10) + val;
        i++;
      }

      nume = (nume * currDeno) + (currNume * deno);
      deno = deno * currDeno;
    }
    int GCD = abs(__gcd(nume, deno));

    return to_string(nume / GCD) + "/" + to_string(deno / GCD);
  }
};

int main()
{

  Solution s;
  s.fractionAddition("12/3+1/2");

  return 0;
}
