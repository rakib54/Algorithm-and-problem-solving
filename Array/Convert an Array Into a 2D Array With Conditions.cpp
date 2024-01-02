#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<vector<int>> findMatrix(vector<int> &nums)
  {
    vector<int> freq(nums.size() + 1);
    vector<vector<int>> result;

    for (int &num : nums)
    {
      if (freq[num] >= result.size())
      {
        cout << freq[num] << " " << result.size() << " " << endl;
        result.push_back({});
      }

      result[freq[num]].push_back(num);
      freq[num]++;
    }

    return result;
  }
};
int main()
{
  Solution s;
  vector<int> nums{1, 3, 4, 1, 2, 3, 1};
  s.findMatrix(nums);
  return 0;
}
