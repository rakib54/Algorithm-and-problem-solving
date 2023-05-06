#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  vector<int>arr {2,3,4,7,11};
  int k = 5;
  vector<int>missing;
  int n = arr.size()-1;
  int a = arr[n-1];
  int j = k;
  int curr = 1;
  for(int i=0;i<=a;i++){
      if(arr[i] != curr){
          missing.push_back(curr);
          j--;
      }
      curr++;
      if(j == 0) break;
  }
  while(j>0){
    missing.push_back(a);
    a++;
    j--;
  }
  for(int i: missing){
    cout<<i<<" ";
  }
  // cout<< missing[k-1];

}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
