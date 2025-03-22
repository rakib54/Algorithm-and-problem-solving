#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
  {
    int n = recipes.size();
    unordered_set<string> st(supplies.begin(), supplies.end());
    vector<string> ans;
    vector<int> isCooked(n, 0);

    int count = n;
    while (count--)
    {
      for (int i = 0; i < n; i++)
      {
        if (isCooked[i])
        {
          continue;
        }

        bool isPassed = true;
        for (int j = 0; j < ingredients[i].size(); j++)
        {
          if (!st.count(ingredients[i][j]))
          {
            isPassed = false;
          }
        }
        if (isPassed)
        {
          st.insert(recipes[i]);
          ans.push_back(recipes[i]);
          isCooked[i] = true;
        }
      }
    }

    return ans;
  }
};

int main()
{
  Solution sol;

  return 0;
}
