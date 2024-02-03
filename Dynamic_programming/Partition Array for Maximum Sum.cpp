#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int n;
    int dp[501];
    int solve(vector<int>&arr, int k, int idx){
        if(idx == n){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int len = 0;
        int maxElement = 0;
        int result = 0;

        for(int i = idx; i < min(idx + k, n); i++){
            len++;
            maxElement = max(maxElement, arr[i]);
            int sum = maxElement * len + solve(arr,k, i+1);
            result = max(result, sum);
        }

        return dp[idx] = result;

    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(dp, -1,sizeof(dp));

        return solve(arr,k,0);
    }
};
int main(){
  Solution s;
  vector<int>nums{1,15,7,9,2,5,10};
  int k = 3;
  s.maxSumAfterPartitioning(nums,k);
  
  return 0;
}
