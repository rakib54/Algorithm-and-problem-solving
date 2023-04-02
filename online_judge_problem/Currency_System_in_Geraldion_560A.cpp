#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int flag = 0;

  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    if(a == 1) flag = 1;
  }
  if(flag) cout<<-1<<endl;
  else cout<<1<<endl;


  return 0;
}