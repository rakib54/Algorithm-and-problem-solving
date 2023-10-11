#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
  {
    vector<int> start, end;
    for (auto &i : flowers)
    {
      start.push_back(i[0]);
      end.push_back(i[1]);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    vector<int> ans;

    for (int i : people)
    {
      int bloomed_flower = upper_bound(start.begin(), start.end(), i) - start.begin();
      int died_flower = lower_bound(end.begin(), end.end(), i) - end.begin();

      ans.push_back(bloomed_flower - died_flower); // people can see
    }

    return ans;
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> flowers{{1, 6}, {3, 7}, {9, 12}, {4, 13}};
  vector<int> people = {2, 3, 7, 11};
  solution.fullBloomFlowers(flowers, people);

  return 0;
}
