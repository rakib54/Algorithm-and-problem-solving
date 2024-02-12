#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;

        for(int i = 0; i < n; i++){
            if(mp[nums[i]] >= n / 2){
                return nums[i];
            }
            mp[nums[i]]++;
        }

        return -1;
    }
};

int main(){
  Solution s;
  vector<int>nums{2,2,3};
  s.majorityElement(nums);
  return 0;
}
