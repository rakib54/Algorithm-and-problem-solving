#include <bits/stdc++.h>
using namespace std;

int main(){
  string s = "01000111";
  int ans = 0;
        
  for(int i=0;i<s.size();i++){
      bool flag = false;
      int zero = 0, one = 0;
      for(int j=i;j<s.size();j++){
          if(s[j] == '1') flag = true;
          if(s[j] == '0' && !flag) zero++;
          else if(s[j] == '1' && flag) one++;
          if(s[j] == '0' && flag) break;
          
          if(zero == one) ans = max(ans, zero + one);
      }
  }
  cout<< ans;
  
  

  return 0;
}

//https://leetcode.com/contest/weekly-contest-339/problems/find-the-longest-balanced-substring-of-a-binary-string/