#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
  {
    map<int, int> mp;

    for (int num : arr1)
    {
      mp[num]++;
    }
    vector<int> result;

    for (int num : arr2)
    {
      if (mp.find(num) != mp.end())
      {
        int n = mp[num];
        mp.erase(num);

        while (n--)
        {
          result.push_back(num);
        }
      }
    }

    // remaining elements
    for (auto i : mp)
    {
      int n = i.second;
      while (n--)
      {
        result.push_back(i.first);
      }
    }

    return result;
  }
};

class Solution2
{
public:
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
  {
    map<int, int> mp;

    for (int i = 0; i < arr2.size(); i++)
    {
      mp[arr2[i]] = i;
    }

    for (auto num : arr1)
    { // those elements are not in arr1
      if (!mp.count(num))
      {
        mp[num] = 1e9;
      }
    }

    auto lambda = [&](int &num1, int &num2)
    {
      if (mp[num1] == mp[num2])
      { // both are 1e9 or same
        return num1 < num2;
      }

      return mp[num1] < mp[num2]; // return those index element that are less between these two
    };

    sort(begin(arr1), end(arr1), lambda);

    return arr1;
  }
};

int main()
{
  Solution solution;
  vector<int> arr1{2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19}, arr2{2, 1, 4, 3, 9, 6};
  solution.relativeSortArray(arr1, arr2);
  return 0;
}
