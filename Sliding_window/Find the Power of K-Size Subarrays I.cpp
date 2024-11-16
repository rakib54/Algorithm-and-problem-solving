#include <bits/stdc++.h>
using namespace std;
#define ll long long

// brute force solution TC-> 0(n^2)
class Solution
{
public:
  vector<int> resultsArray(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<int> result;

    for (int i = 0; i < n - k + 1; i++)
    {
      int curr = nums[i];
      bool isConsecutive = true;
      for (int j = i + 1; j < i + k; j++)
      {
        if (nums[j] == curr + 1)
        {
          curr = nums[j];
        }
        else
        {
          isConsecutive = false;
          break;
        }
      }
      isConsecutive ? result.push_back(curr) : result.push_back(-1);
    }

    return result;
  }
};

// sliding window TC -> 0(n)
class Solution
{
public:
  vector<int> resultsArray(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<int> result(n - k + 1, -1);

    int count = 1;

    // preprocess the first k size window
    for (int i = 1; i < k; i++)
    {
      if (nums[i] == nums[i - 1] + 1)
      {
        count++;
      }
      else
      {
        count = 1;
      }
    }
    if (count == k)
    {
      result[0] = nums[k - 1];
    }

    int i = 1, j = k;

    while (j < n)
    {
      if (nums[j] == nums[j - 1] + 1)
      {
        count++;
      }
      else
      {
        count = 1;
      }

      if (count >= k)
      {
        result[i] = nums[j];
      }
      i++;
      j++;
    }

    return result;
  }
};

int main()
{

  return 0;
}
