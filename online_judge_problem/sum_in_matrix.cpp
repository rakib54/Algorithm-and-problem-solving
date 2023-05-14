#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  vector<vector<int>> nums{{7,2,1},{6,4,2},{6,5,3}, {3,2,1}};
  int n = nums.size();
  int m = nums[0].size();
  ll sum = 0;
  for(int i=0;i<m;i++){
    int num = -1;
    for(int j=0;j<n;j++){
      num = max(num, nums[j][i]);
    }
    sum += num;
  }
  cout<<sum;
}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
