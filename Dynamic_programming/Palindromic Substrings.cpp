#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int dp[1001][1001];
    bool isPalindrome(int start, int end, string &s){
        if(start >= end){
            return true;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        
        if(s[start] == s[end]){
            return dp[start][end] = isPalindrome(start + 1 , end - 1, s);
        }

        return dp[start][end] = false;
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++){ // check all possible options
            for(int j = i; j < n; j++){
                if(isPalindrome(i,j,s)){
                    count++;
                }
            }
        }
        return count;
    }
};

int main(){
  Solution s;
  s.countSubstrings("aaaaaa");
  return 0;
}
