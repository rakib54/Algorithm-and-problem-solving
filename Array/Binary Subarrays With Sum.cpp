#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        int n = nums.size();
        unordered_map<int,int>mp;
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            
            if(sum == goal){
                count++;
            }
            if(mp.find(sum-goal) != mp.end()){
                count += mp[sum-goal];
            }
            mp[sum]++;
        }
        
        return count;
    }
};

int main(){
  Solution s;
  vector<int>nums{1,0,1,0,1};
  int goal = 2;
  s.numSubarraysWithSum(nums,goal);
  return 0;
}
