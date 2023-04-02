#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> reward1{1,1} ;
  vector<int> reward2 {1,1};
  int k = 2;
  vector<pair<int,int>>v;
  int n = reward1.size();

  for(int i = 0; i < n; i++){
    v.push_back({reward1[i] - reward2[i], i});
  }
  // for(auto i: v){
  //   cout<<i.first<<" "<<i.second<<endl;
  // }
  cout<<endl;
  sort(v.begin(), v.end(), greater<>());

  // for(auto i: v){
  //   cout<<i.first<<" "<<i.second<<endl;
  // }
  int ans = 0;
  for(int i=0;i<n;i++){
    int idx = v[i].second;
    if(i < k) ans += reward1[idx];
    else ans += reward2[idx];
  }
  cout<<endl;
  cout<<ans;

  return 0;
}

// https://leetcode.com/contest/weekly-contest-339/problems/mice-and-cheese/