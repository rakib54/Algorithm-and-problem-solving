#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  vector<int> obstacles{3,1,5,6,4,2};
  int n = obstacles.size();
  vector<int>ans(n,1), lis;

  for(int i=0;i<n;i++){
      int idxtoInsert = upper_bound(lis.begin(),lis.end(), obstacles[i]) - lis.begin();
      if(lis.size() == idxtoInsert){
          lis.push_back(obstacles[i]);
      }
      else {
          lis[idxtoInsert] = obstacles[i];
      }
      ans[i] = idxtoInsert + 1;
  }
  

  for(int i: ans){
    cout<<i<<" ";
  }

}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
