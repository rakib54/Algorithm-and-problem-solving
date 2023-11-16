#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string findDifferentBinaryString(vector<string> &nums)
  {
    string ans;
    // if we search on diagonal and reverse them we definitely get the missing number
    for (int i = 0; i < nums.size(); i++)
    {
      ans += nums[i][i] == '0' ? '1' : '0';
    }

    return ans;
  }
};

int main()
{
  Solution solution;
  vector<string> nums{"01", "10"};
  solution.findDifferentBinaryString(nums);

  return 0;
}
