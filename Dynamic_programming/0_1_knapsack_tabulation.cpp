#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long dp[102][N];
int wt[N], val[N];

int main(){
    int n,w;
    cin>>n>>w;
    for(int i=1;i<=n;i++){
        cin>>wt[i]>>val[i];
    }

    // base case
    for(int i=0;i<=w;i++){
        dp[0][i] = 0;
    }
    // loop over the states
    for(int i=1;i<=n;i++){
        for(int cap=0;cap<=w;cap++){
            // corner case
            if(cap < wt[i]){
                dp[i][cap]  = dp[i-1][cap];
            }
            // calculate the result for smaller sub problems
            else {
                dp[i][cap] = max(
                    val[i] + dp[i-1][cap-wt[i]],
                    dp[i-1][cap]
                );
            }
        }
    }

    cout<<dp[n][w]<<endl;

    return 0;
}
