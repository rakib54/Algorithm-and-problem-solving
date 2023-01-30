#include <bits/stdc++.h>
using namespace std;
const int N = 102;
const int M = 1e5+5;
int dp[N][M];
int nums[N];

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    dp[0][0] = 1; // if n == 0 and if target == 0 return 1;

    for(int i=1;i<=m;i++){
        dp[0][i] = 0;
    }

    for(int i=1;i<=n;i++){
        for(int target=1;target<=m;target++){
            // calculate ans from smaller sub problems
            int ans1 = dp[i-1][target];
            if(target < nums[i]){
                dp[i][target] = ans1;
            }
            else {
                int ans2 = dp[i-1][target - nums[i]];
                dp[i][target] = ans1 or ans2;
            }
        }
    }
    cout<<(dp[n][m] ? "True" : "false")<<endl;

//    for(int i=0;i<=n;i++){
//        for(int j=0;j<=m;j++){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    return 0;
}


/**
3 9
4 2 3

6 9
3 34 4 12 5 2

100 5142
57 68 27 100 69 49 100 51 71 63 77 20 63 4 11 31 21 23 94 5 56 54 15 88 61 89 5 22 83 55 90 39 74 16 38 42 17 37 93 39 52 69 59 14 24 21 96 96 43 89 100 51 95 15 38 7 55 42 28 37 49 69 75 74 36 12 16 52 1 60 43 52 80 53 65 55 73 12 50 68 100 50 18 94 16 7 100 70 1 79 58 49 47 32 74 35 95 89 38 47


**/
