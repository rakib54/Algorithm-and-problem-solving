#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;

  while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
 
    int count = 0;
    int i=0, j = s.size()-1;

    while(i<j){
      if(s[i] == s[j]){  // if both char are equal we stop and calculate the length of the remaining string
        break;
      }
      else {
        count++;
      }
      i++;
      j--;
    }
    
    cout<<n-(2 * count)<<endl; //calculate the length of the remaining string
  }


  return 0;
}



// https://codeforces.com/contest/1791/problem/C