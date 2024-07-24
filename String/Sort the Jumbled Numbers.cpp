#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int getMappedNumber(vector<int> &mapping, int number)
  {
    if (number < 10)
    {
      return mapping[number];
    }
    int mappedValue = 0;
    int placeVal = 1;
    while (number)
    {
      int lastDigit = number % 10;
      mappedValue += (placeVal * mapping[lastDigit]);
      placeVal *= 10;
      number /= 10;
    }

    return mappedValue;
  }
  vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
  {
    vector<pair<int, int>> vec;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
      int currNum = nums[i];
      int mappedNum = getMappedNumber(mapping, currNum);
      vec.push_back({mappedNum, i});
    }
    sort(vec.begin(), vec.end());
    vector<int> result;

    for (auto &i : vec)
    {
      int originalIdx = i.second;
      result.push_back(nums[originalIdx]);
    }

    return result;
  }
};

class Solution2
{
public:
  string getMappedNum(vector<int> &mapping, string num)
  {
    string mappedNum = "";

    for (int i = 0; i < num.size(); i++)
    {
      char ch = num[i];
      int intCh = ch - '0';
      mappedNum += to_string(mapping[intCh]);
    }

    return mappedNum;
  }
  vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
  {
    vector<pair<int, int>> vec;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
      string numStr = to_string(nums[i]);
      string mapStr = getMappedNum(mapping, numStr);
      int mappedNum = stoi(mapStr);

      vec.push_back({mappedNum, i});
    }
    sort(vec.begin(), vec.end());
    vector<int> result;

    for (auto &i : vec)
    {
      int originalIdx = i.second;
      result.push_back(nums[originalIdx]);
    }

    return result;
  }
};
int main()
{
  vector<int> mapping{8, 9, 4, 0, 2, 1, 3, 5, 7, 6};
  vector<int> nums{991, 338, 38};
  Solution solution;
  solution.sortJumbled(mapping, nums);
  return 0;
}
