// https://atcoder.jp/contests/dp/tasks/dp_h

#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
const int N = 1002;
int dp[N][N];
int grid[N][N];

long long total_paths(int i,int j){
    if(i == 0 && j == 0) {
        return 1;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    long long ans = 0;
    if(i > 0 && grid[i][j] != -1){
        ans+= total_paths(i-1,j) % M;
    }
    if(j > 0 && grid[i][j] != -1){
        ans+= total_paths(i,j-1) % M;
    }
    dp[i][j] = ans;
    return ans;
}

int main (){
    int h,w;
    cin>>h>>w;
    string s;
    for(int i=0;i<h;i++){
        cin>>s;
        for(int j=0;j<w;j++){
            if(s[j] == '#'){
                grid[i][j] = -1;
            }
        }
    }
    memset(dp,-1,sizeof(dp));

    cout<<total_paths(h-1,w-1) % M<<endl;

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9+7;
const int N = 1002;
long long dp[N][N];
int maze[N][N];
int h,w;

long long total_paths(int i,int j){
    if(i == h-1 && j == w-1) { // if reached last index
        return 1;
    }
    if(i >= h || j >= w) return 0; // if out of bound

    if(maze[i][j] == -1) return 0; // if found # in the path

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    long long ans = 0;
    ans+= total_paths(i+1,j) % M;
    ans+= total_paths(i,j+1) % M;

    dp[i][j] = ans;
    return ans;
}

int main (){

    cin>>h>>w;
    string s;
    for(int i=0;i<h;i++){
        cin>>s;
        for(int j=0;j<w;j++){
            if(s[j] == '#'){
                maze[i][j] = -1;
            }
        }
    }
    memset(dp,-1,sizeof(dp));

    cout<<total_paths(0,0) % M<<endl;

    return 0;
}


*/

