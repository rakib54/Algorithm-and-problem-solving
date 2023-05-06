#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  string s;
  cin>>s;
  int count = 0;

  string c = "codeforces";
  for(int i=0;i<c.size();i++){
    if(s[i] != c[i]){
      count++;
    }
  }
  cout<<count<<endl;

}

int main(){
  ll test = 1;
  cin>>test;
  while(test--){
    solve();
  }
  return 0;
}
