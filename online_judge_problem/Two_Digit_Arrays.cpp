#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> nums1{3,8,4,2,6,1};
  vector<int> nums2{4,7,8,5,2,3,6};

  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
  unordered_map<int,int>mp;

  
  for(int i=0;i<nums1.size();i++){
      mp[nums1[i]]++;
  }
  for(int i=0;i<nums2.size();i++){
      if(mp.find(nums2[i]) != mp.end()){
          cout<< nums2[i];
          return 0;
      }
  }
  int ans1 = nums1[0] * 10  + nums2[0];
  int ans2 = nums2[0] * 10  + nums1[0];
  
  if(ans1 > ans2) cout<< ans2;
  else cout<< ans1;


  return 0;
}