#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  vector<int> player1 ={9,7,10,7};
  vector<int> player2 ={10,2,4,10};

  bool isdouble = false;
  int point1 = 0, point2 = 0;
  for(int i=0;i<2 && i<player1.size(); i++){
    if(isdouble){
      point1 += 2 * player1[i];
    }
    else {
      if(player1[i] == 10) isdouble = true;
      point1 += player1[i];
    }
  }

  for(int i=2;i<player1.size();i++){
    if(player1[i-1] == 10 || player1[i-2] == 10){
      point1 += 2 *  player1[i];
    }
    else {
      point1 += player1[i];
    }
  }
  isdouble = false;

  for(int i=0;i<2 && i<player2.size(); i++){
    if(isdouble){
      point2 += 2 * player2[i];
    }
    else {
      if(player2[i] == 10) isdouble = true;
      point2 += player2[i];
    }
  }

  for(int i=2;i<player2.size();i++){
    if(player2[i-1] == 10 || player2[i-2] == 10){
      point2 += 2 *  player2[i];
    }
    else {
      point2 += player2[i];
    }
  }

  cout<<point1<<" "<<point2<<endl;
  if(point1 == point2) cout<< 0;
  else if(point1 > point2) cout<< 1;
  else cout<<2;

}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
