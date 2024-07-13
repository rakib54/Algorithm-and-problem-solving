#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
  {
    int n = positions.size();
    vector<int> actual_idx(n);
    iota(begin(actual_idx), end(actual_idx), 0);

    auto lambda = [&](int &i, int &j)
    {
      if (positions[i] < positions[j])
      { // lowest position robot in first
        return true;
      }
      return false;
    };

    sort(actual_idx.begin(), actual_idx.end(), lambda);

    vector<int> ans;
    stack<int> st;

    for (auto curr_idx : actual_idx)
    {
      if (directions[curr_idx] == 'R')
      { // moving right
        st.push(curr_idx);
      }
      else
      { // moving left
        while (!st.empty() && healths[curr_idx] > 0)
        {
          int top_idx = st.top();
          st.pop();
          if (healths[top_idx] < healths[curr_idx])
          {
            healths[top_idx] = 0;
            healths[curr_idx] -= 1;
          }
          else if (healths[top_idx] > healths[curr_idx])
          {
            healths[curr_idx] = 0;
            healths[top_idx] -= 1;
            st.push(top_idx);
          }
          else
          {
            healths[curr_idx] = 0;
            healths[top_idx] = 0;
          }
        }
      }
    }

    for (int i = 0; i < n; i++)
    {
      if (healths[i] > 0)
      {
        ans.push_back(healths[i]);
      }
    }

    return ans;
  }
};

int main()
{
  Solution solution;
  vector<int> positions{3, 5, 2, 6};
  vector<int> healths{10, 10, 15, 12};
  string directions = "RLRL";
  solution.survivedRobotsHealths(positions, healths, directions);
  return 0;
}
