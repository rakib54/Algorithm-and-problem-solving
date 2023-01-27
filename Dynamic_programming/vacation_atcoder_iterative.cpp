#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int dp[N][4];
int happiness[N][4];

int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>happiness[i][j];
        }
    }
    // base case
    for(int i=1;i<=3;i++){
        dp[1][i] = happiness[1][i];
    }

    for(int day = 1;day<=n;day++){
        for(int curr_task = 1;curr_task<=3;curr_task++){
            int max_profit = 0;
            for(int last =1;last<=3;last++){
                if(last !=curr_task){
                    int candidate_ans = dp[day-1][last] + happiness[day][curr_task];
                    max_profit = max(max_profit, candidate_ans);
                }
            }
            dp[day][curr_task] = max_profit;
        }
    }

    int ans1 = dp[n][1];
    int ans2 = dp[n][2];
    int ans3 = dp[n][3];

    cout<<max({ans1,ans2, ans3})<<endl;

    return 0;
}
