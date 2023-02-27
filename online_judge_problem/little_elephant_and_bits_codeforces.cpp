#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  
  for(int i=0;i<s.size();i++){
    if(s[i] == '0'){
      s.erase(i,1);
      break;
    }
    if(i == s.size()-1){
      s.erase(i);
    }
  }
  cout<<s<<endl;

  return 0;
}