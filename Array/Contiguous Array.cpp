#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int currSum = 0;
        mp[currSum] = -1;
        int maxLength = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                currSum -= 1;
            }else {
                currSum++;
            }
            if(mp.find(currSum) != mp.end()){
                maxLength = max(maxLength,i - mp[currSum]);
            }
            else {
                mp[currSum] = i;
            }
        }

        return maxLength;

    }
};

int main(){
  Solution s;

  vector<int>nums{1,0,1,0,0,0,1,1,1};
  s.findMaxLength(nums);
  
  return 0;
}
