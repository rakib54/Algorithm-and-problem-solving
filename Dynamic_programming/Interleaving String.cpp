#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int m,n,N;
    int dp[101][101];
    bool solve(int i, int j,string &s1, string &s2, string &s3){
        if(i == m && j == n && i+j == N){
            return true;
        }
        if(i+j >= N) return false;

        if(dp[i][j]!= -1){
            return dp[i][j];
        }
        bool result = false;

        if(s1[i] == s3[i+j]){
            result = solve(i+1, j,s1,s2,s3);
        }
        if(result == true){
            return result;
        }
        if(s2[j] == s3[i+j]){
            result = solve(i, j+1,s1,s2,s3);
        }

        return dp[i][j] = result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.length();
        n = s2.length();
        N = s3.length();
        memset(dp, -1, sizeof(dp));

        return solve(0,0,s1,s2,s3);
    }
};

int main(){
  Solution s;
  string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
  bool res = s.isInterleave(s1,s2,s3);
  
  return 0;
}

/**
 class Solution {
public:
    int m,n,N;
    int dp[101][101][201];
    bool solve(int i, int j, int k,string &s1, string &s2, string &s3){
        if(i == m && j == n && k == N){
            return true;
        }
        if(k >= N) return false;

        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        bool result = false;

        if(s1[i] == s3[k]){
            result = solve(i+1, j,k+1,s1,s2,s3);
        }
        if(result == true){
            return result;
        }
        if(s2[j] == s3[k]){
            result = solve(i, j+1, k+1,s1,s2,s3);
        }

        return dp[i][j][k] = result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.length();
        n = s2.length();
        N = s3.length();
        memset(dp, -1, sizeof(dp));

        return solve(0,0,0,s1,s2,s3);
    }
}; 
 */
