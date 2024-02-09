#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>dp(n,1);

        vector<int>prev_idx(n, -1); // store prev idx

        int last_choosen_idx = 0;  // store largest subsets last value
        int maxL = 0;
        

        for(int i = 1; i< n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        prev_idx[i] = j;
                    }
                }
                if(dp[i] > maxL){
                    maxL = dp[i];
                    last_choosen_idx = i;
                }
            }
        }
        vector<int>result;
        while(last_choosen_idx != -1){
            result.push_back(nums[last_choosen_idx]);
            last_choosen_idx = prev_idx[last_choosen_idx];
        }

        return result;
    }
};

int main(){
  Solution s;
  vector<int>nums{3,15,32,8,64};
  s.largestDivisibleSubset(nums);

  
  return 0;
}
