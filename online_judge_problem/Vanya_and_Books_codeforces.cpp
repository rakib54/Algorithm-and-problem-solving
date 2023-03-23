#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  long long ans = 0;

  for(int i=9;n>0;i *=10){
    ans += n;
    n -= i;
  }
  cout<<ans<<endl;

  return 0;
}

// codeforces 552B