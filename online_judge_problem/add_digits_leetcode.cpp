#include <bits/stdc++.h>
using namespace std;
#define ll long long

int sum = 0;
int countDigits(int num){
  int count = 0;
  sum = 0;
  while(num != 0){
    sum += num % 10;
    num /= 10;
    count++;
  }
  return count;
}

void solve(){
  int num = 38;
  while(countDigits(num) > 1){
    num = sum;
  }
  cout<<num<<endl;
}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}

// https://leetcode.com/problems/add-digits/description/
