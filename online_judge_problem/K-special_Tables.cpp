#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n,k,i,j,sum = 0, ans = 0;
  ll p;
  cin>>n>>k;
  ll pp = 1;
  p = n*n;
  ll a[n+1][n+1];

  for(i=1;i<=n;i++){
    for(j=n;j>=k;j--){
      a[i][j] = p;
      p--;
    }
    for(j=1;j<k;j++){
      a[i][j] = pp;
      pp++;
    }
    sum += a[i][k];
  }
  cout<<sum<<endl;

  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }


  return 0;
}