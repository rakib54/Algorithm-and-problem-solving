#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string largestNumber(vector<int> &nums)
  {
    string result = "";
    auto myComparator = [](int &a, int &b)
    {
      string s1 = to_string(a);
      string s2 = to_string(b);

      return s1 + s2 > s2 + s1;
    };

    sort(nums.begin(), nums.end(), myComparator);

    if (nums[0] == 0)
    { // cornar case
      return "0";
    }

    for (int &num : nums)
    {
      string s = to_string(num);
      result += s;
    }

    return result;
  }
};

int main()
{
  Solution s;
  vector<int> nums{3, 30, 34, 5, 9};
  s.largestNumber(nums);

  return 0;
}
