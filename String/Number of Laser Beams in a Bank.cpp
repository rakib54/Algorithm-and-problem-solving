#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int numberOfBeams(vector<string> &bank)
  {
    int n = bank.size();
    vector<int> cell;
    int result = 0;

    for (int i = 0; i < n; i++)
    {
      string s = bank[i];
      int count = 0;
      for (auto ch : s)
      {
        if (ch == '1')
        {
          count++;
        }
      }
      if (count != 0)
      {
        cell.push_back(count);
      }
    }
    if (cell.size() == 0)
    {
      return 0;
    }
    for (int i = 0; i < cell.size() - 1; i++)
    {
      result += (cell[i] * cell[i + 1]);
    }

    return result;
  }
};

int main()
{
  Solution s;
  vector<string> bank{"011001", "000000", "010100", "001000"};
  s.numberOfBeams(bank);
  return 0;
}
