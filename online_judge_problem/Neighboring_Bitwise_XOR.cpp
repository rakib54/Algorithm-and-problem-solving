#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  vector<int> derived{1,1,10};
  int ans = accumulate(derived.begin(),derived.end(),0);
  cout<<ans;

}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
