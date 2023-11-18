#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    bool isPossible(int mid, vector<int>& nums, int k){
        long long int windowSum = 0, totalSum = 0;
        for(int i = 0; i<mid; i++){
            windowSum += nums[i];
        }

        totalSum = (1ll) * nums[mid - 1] * mid;

        if(totalSum - windowSum <= k) {
            return 1;
        }

        int j = 0; // check all the sliding window sum

        for(int i = mid ;i<nums.size();i++){
            windowSum -= nums[j];
            windowSum += nums[i];
            totalSum = (1ll)* nums[i] * mid;

            if(totalSum - windowSum <= k){
                return 1;
            }
        }
        return 0;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 1, high = n;
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(isPossible(mid, nums,k)){
                low = mid + 1;
                ans = mid;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
        
    }
};

int main(){
  Solution s;
  vector<int>nums {1,2,4};
  int k = 5;
  s.maxFrequency(nums,k);
  return 0;
}
