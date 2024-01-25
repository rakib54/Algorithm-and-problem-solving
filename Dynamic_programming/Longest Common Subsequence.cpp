#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int n, m;
    int dp[1001][1001];
    int solve(string &text1, string &text2, int i, int j){
        if(i >= n || j >= m){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(text1[i] == text2[j]){ // if two char are equal
            return 1 + solve(text1, text2, i+1, j + 1);
        }else {
            int take_i = solve(text1, text2, i, j + 1); //explore
            int take_j = solve(text1, text2, i+1, j);
            return dp[i][j] = max(take_i, take_j);
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();
        memset(dp, -1, sizeof(dp));
        return solve(text1, text2, 0, 0);
    }
};

int main(){
  Solution s;
  s.longestCommonSubsequence("abcde","ace");
  return 0;
}
