#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int n;
    int dp[101];
    int solve(vector<int>& nums, int i){
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int take = nums[i] + solve(nums, i + 2);
        int not_take = solve(nums, i + 1);

        return dp[i] = max(take, not_take);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1,sizeof(dp));
        return solve(nums,0);
    }
};

int main(){
  Solution s;
  vector<int>nums{2,7,9,3,1};
  s.rob(nums);
  
  return 0;
}
