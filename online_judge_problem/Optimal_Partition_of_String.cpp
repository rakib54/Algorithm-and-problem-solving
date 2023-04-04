#include <bits/stdc++.h>
using namespace std;

int main(){
  string s = "hdklqkcssgxlvehva";
  int cnt = 0;
  int n = s.size();
  map<char,int>mp;
  
  for(int i=0;i<n;i++){
      if(mp.find(s[i]) != mp.end()){
          cnt++;
          mp.clear();
      }
      mp[s[i]]++;
  }
  cout<< cnt+1; // take +1 because of the last partion is not taken


  return 0;
}