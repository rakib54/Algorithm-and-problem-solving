#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>>ans;
        
        for(int i = 0; i<n-2;i++ ){
            int min = nums[i];
            vector<int>v;
            for(int j = i; j<i+3;j++){
                if((nums[j] - min) <= k){
                    v.push_back(nums[j]);
                }
                else {
                    return {};
                }
            }
            i += 2;
            ans.push_back(v);
        }
        
        return ans;
        
    }
};

int main(){
  Solution s;
  vector<int>nums{1,3,4,8,7,9,3,5,1};
  s.divideArray(nums,2);
  return 0;
}
