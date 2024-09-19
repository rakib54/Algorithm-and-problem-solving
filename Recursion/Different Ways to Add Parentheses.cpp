#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> diffWaysToCompute(string s)
  {
    vector<int> res;

    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '*' || s[i] == '+' || s[i] == '-')
      {
        vector<int> left = diffWaysToCompute(s.substr(0, i));
        vector<int> right = diffWaysToCompute(s.substr(i + 1));

        for (auto x : left)
        {
          for (auto y : right)
          {
            if (s[i] == '+')
              res.push_back(x + y);
            else if (s[i] == '-')
              res.push_back(x - y);
            else if (s[i] == '*')
              res.push_back(x * y);
          }
        }
      }
    }
    if (res.empty())
      res.push_back(stoi(s));
    return res;
  }
};

int main()
{
  Solution solution;
  string s = "2*3-4*5";
  solution.diffWaysToCompute(s);

  return 0;
}
