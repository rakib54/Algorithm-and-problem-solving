#include <bits/stdc++.h>
using namespace std;

int main(){
  
  vector<int>nums{1,3,4,1,2,3,1};
  vector<vector<int>>ans;
  map<int,int>mp;

  for(int i=0;i<nums.size();i++){
    mp[nums[i]]++;

  }
  int mx = 0;
  for(auto it: mp){
    mx = max(mx, it.second);
  }
  
  for(int i=0;i<mx;i++){
    vector<int>v;
    for(auto it: mp){
      // cout<<it.first<<":  "<<it.second<<endl;
      if(it.second > 0){
        v.push_back(it.first);
        mp[it.first]--;
      }
    }
    ans.push_back(v);
  }
  
  

  return 0;
}

// https://leetcode.com/contest/weekly-contest-339/problems/convert-an-array-into-a-2d-array-with-conditions/