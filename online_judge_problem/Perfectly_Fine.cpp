// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// void solve(){
//   int n;
//   cin>>n;
//   if(n == 1){
//     int a;
//     string s;
//     cin>>a>>s;
//     if(s == "11"){
//       cout<<a<<endl;
//       return;
//     }
//   }
//   int ans1 = INT_MAX;
//   int ans2 = INT_MAX;
//   int ans3 = INT_MAX;
//   unordered_set<string>check;
//   for(int i=0;i<n;i++){
//     int a;
//     string s;
//     cin>>a>>s;
//     check.insert(s);
//     int ans10 = 0, ans01 = 0, ans11 = 0;
//     if(s == "10"){
//       ans10 = a;
//       ans1 = min(ans1, ans10);
//     }
//     else if(s == "01"){
//       ans01 = a;
//       ans2 = min(ans2, ans01);
//     }
//     else if(s == "11"){
//       ans11 = a;
//       ans3 = min(ans3, ans11);
//     }
//     else continue;

//   }
//   int final_ans = min(ans3,(ans1 + ans2));
//   if(check.count("11") == 1  && (check.count("10") == 1 && check.count("01") == 1)){
//     cout<<final_ans<<endl;
//   }
//   else if(check.count("11") == 1 && (check.count("10") == 0 || check.count("01") == 0)){
//     cout<<ans3<<endl;
//   }
//   else if((check.count("10") == 1 && check.count("01") == 1) && check.count("11") == 0){
//     cout<<ans1 + ans2<<endl;
//   }
//   else {
//     cout<<-1<<endl;
//   }

// }

// int main(){
//   ll test = 1;
//   cin>>test;
//   while(test--){
//     solve();
//   }
//   return 0;
// }


// Is not solve yet