#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  int n;
  cin>>n;
  int arr[n];
  int count = 0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int ans = 0;
  for(int i=0;i<n;i++){
    if(arr[i] == 0){
      count++;
      ans = max(ans,count);
    }
    else count = 0;
  }
  cout<<ans<<endl;

}

int main(){
  ll test = 1;
  cin>>test;
  while(test--){
    solve();
  }
  return 0;
}
