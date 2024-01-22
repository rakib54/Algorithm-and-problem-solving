#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(2);
        unordered_map<int,int>mp;
        for(auto num: nums){
            mp[num]++;
        }

        for(int i = 1; i <= n; i++){
            if(mp.find(i) != mp.end() && mp[i] > 1){
                result[0] = i;
            }
            else if(mp.find(i) == mp.end()){
                result[1] = i;
            }
            
        }
        return result;
    }
};

int main(){
  Solution s;
  vector<int>nums{1,2,2,4};
  s.findErrorNums(nums);  
  return 0;
}
