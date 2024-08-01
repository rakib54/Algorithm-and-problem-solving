#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int countSeniors(vector<string> &details)
  {
    int n = details.size();

    int count = 0;

    for (int i = 0; i < n; i++)
    {
      string age = details[i].substr(11, 2);
      int ageToNum = stoi(age);

      if (ageToNum > 60)
      {
        count++;
      }
    }

    return count;
  }
};

int main()
{
  Solution solution;
  vector<string> details{"7868190130M7522", "5303914400F9211", "9273338290F4010"};
  solution.countSeniors(details);

  return 0;
}
