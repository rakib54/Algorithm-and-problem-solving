#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;

        for(auto num: nums1){
            mp[num]++;
        } 

        for(auto num: nums2){
            if(mp.find(num) != mp.end()){
                return num;
            }
        }

        return -1;
    }
};

int main(){
  Solution s;
  vector<int>nums1{1,1,2};
  vector<int>nums2{1};
  s.getCommon(nums1,nums2);  
  return 0;
}
