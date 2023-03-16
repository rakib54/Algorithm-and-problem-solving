#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m, s[100001];
  cin>>n>>m;
  s[0] = 0;
  for(int i=1;i<=n;i++){
    int c,t;
    cin>>c>>t;
    s[i] = s[i-1] + c*t; 
  }

  int song = 1;
  while(m--){
    int v;
    cin>>v;
    while(v > s[song]){
      song +=1;
    }
    cout<<song<<endl;
  }

  return 0;
}

// problem/302/B codeforces