#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
  {
    unordered_set<int> st;

    for (int num : arr1)
    {
      while (num > 0 && !st.count(num))
      {
        st.insert(num);
        num /= 10;
      }
    }

    int result = 0;

    for (int num : arr2)
    {
      while (!st.count(num) && num > 0)
      {
        num /= 10;
      }
      if (num > 0)
      {
        result = max(result, static_cast<int>(log10(num) + 1));
      }
    }
    return result;
  }
};

int main()
{
  Solution solution;
  vector<int> arr1{1, 10, 100}, arr2{1000};
  solution.longestCommonPrefix(arr1, arr2);
  return 0;
}
