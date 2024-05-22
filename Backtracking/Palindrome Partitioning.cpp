#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int n;
    bool palindrome(string &s, int l, int r){
        while(l <= r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void solve(vector<vector<string>>&substring, vector<string>&v, int idx, string &s){
        if(idx == n){
            substring.push_back(v);
            return;
        }

        for(int i = idx; i < s.size(); i++){
            if(palindrome(s, idx, i)){
                v.push_back(s.substr(idx, i - idx + 1));
                solve(substring, v, i+1, s);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<vector<string>>substring;
        vector<string>v;
        solve(substring, v, 0, s);

        return substring;
    }
};

int main(){
  string s = "aab";
  Solution solution;
  solution.partition(s);
  return 0;
}
