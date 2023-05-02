#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int a,b;
    cin>>a>>b;
    string s[a];
    for(int i=0;i<a;i++){
      cin>>s[i];
    }
    int cnt = 0;
    for(int i=0;i<a;i++){
      if(s[i] == s[0]){
        cnt++;
      }
    }
    cout<<cnt<<endl;

}

int main(){
  ll test = 1;
  cin>>test;
  while(test--){
    solve();
  }
  return 0;
}
