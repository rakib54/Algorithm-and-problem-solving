#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string countOfAtoms(string formula)
  {
    int n = formula.size();
    stack<unordered_map<string, int>> st;
    st.push(unordered_map<string, int>());

    int i = 0;
    while (i < n)
    {
      if (formula[i] == '(')
      {
        st.push(unordered_map<string, int>());
        i++;
      }
      else if (formula[i] == ')')
      {
        unordered_map<string, int> curr = st.top();
        st.pop();
        i++;

        // check any integer is present or not
        string mult;
        while (i < n && isdigit(formula[i]))
        {
          mult.push_back(formula[i]);
          i++;
        }
        if (!mult.empty())
        {
          int multiplier = stoi(mult);
          for (auto &it : curr)
          {
            string ele = it.first;
            int count = it.second;
            curr[ele] = count * multiplier;
          }
        }
        // merge with stack top item

        for (auto &it : curr)
        {
          string ele = it.first;
          int count = it.second;

          st.top()[ele] += count;
        }
      }
      else
      {
        string currElement; // exp: H
        currElement.push_back(formula[i]);
        i++;
        // if ele is Mg
        while (i < n && isalpha(formula[i]) && islower(formula[i]))
        {
          currElement.push_back(formula[i]);
          i++;
        }
        string currCount; // count digit --> Mg2

        while (i < n && isdigit(formula[i]))
        {
          currCount.push_back(formula[i]);
          i++;
        }
        int currCountInt = currCount.empty() ? 1 : stoi(currCount);
        st.top()[currElement] += currCountInt;
      }
    }
    string result;
    // last element is top of the stack
    map<string, int> sortedEle(begin(st.top()), end(st.top()));

    for (auto &it : sortedEle)
    {
      string element = it.first;
      result += element;
      int count = it.second;
      if (count > 1)
      {
        result += to_string(count);
      }
    }
    return result;
  }
};

int main()
{
  string s = "Mg(OH)2";
  Solution solution;
  solution.countOfAtoms(s);
  return 0;
}
