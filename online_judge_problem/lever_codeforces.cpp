#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
  string s;
  cin>>s;
  int l = s.length();
  int k = 0;

  ll ans1 = 0, ans2 = 0;

  while(s[k] != '^'){
    k++;
  }
  // cout<<"k: "<<k<<endl;
  for(int i=0;i<k;i++){
    if(s[i] >= '1' && s[i] <= '9'){
      ans1 += (s[i] - '0') * (k-i);
    }
  }

  for(int i=k+1;i<l;i++){
    if(s[i] >= '1' && s[i] <= '9'){
      ans2 += (s[i] - '0') * (i-k);
    }
  }
  // cout<<ans1 <<" "<<ans2<<endl;

  if(ans1 == ans2) {
    cout<<"balance"<<endl;
  }
  else if(ans1 > ans2) {
    cout<<"left"<<endl;
  }
  else {
    cout<<"right"<<endl;
  }


  return 0;
}