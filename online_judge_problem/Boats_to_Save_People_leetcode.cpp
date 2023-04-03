#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> people{3,5,3,4};
  int limit = 5;
  int ans = 0;
  int n = people.size();
  sort(people.begin(), people.end());
  int i = 0, j = n-1;
  
  while(i<=j){
      if(people[i] + people[j] <=limit){
          i++;
      }
      ans++;
      j--;

  }
  cout<< ans;


  return 0;
}