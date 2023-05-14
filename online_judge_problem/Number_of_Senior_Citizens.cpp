#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  vector<string> details{"5612624052M0130","5378802576M6424","5447619845F0171","2941701174O9078"};

    int count = 0;
   for(int i=0;i<details.size();i++){
      string s = details[i];
      string age;
      age.push_back(s[11]);
      age.push_back(s[12]);
      cout<<stoi(age)<<endl;
      int curr_age = stoi(age);

      if(curr_age > 60) count++;
   }
  

  cout<<count ;

}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
