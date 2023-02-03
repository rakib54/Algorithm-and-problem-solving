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

