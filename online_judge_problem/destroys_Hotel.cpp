#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,s;
  cin >> n >> s;
  int ans = s;
  while(n--){
    int f,t;
    cin >> f >> t;
    ans = (ans > (f + t) ? ans : (f + t));
  }
  cout<<ans<<endl;


  return 0;
}