#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for(int i = 0; i < n; i++){
            totalSum += nums[i];
        }

        int expected_sum = n * (n + 1)/2;

        return  expected_sum - totalSum;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        int expected_sum = n * (n + 1)/2;

        return  expected_sum - totalSum;
    }
};

int main(){
  Solution s;
  vector<int>nums{1,2};
  s.missingNumber(nums);
  return 0;
}
