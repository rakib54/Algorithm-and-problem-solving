#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    bool hasDuplicate(string &s1, string &s2){
        vector<int>freq(26);
        for(char ch: s1){
            if(freq[ch-'a'] > 0){
                return true;
            }
            freq[ch-'a']++;
        }
        for(char &ch: s2){
            if(freq[ch - 'a'] > 0){
                return true;
            }
        }
        return false;
    }
    int n;
    int solve(vector<string>& arr, int i, string temp){
        if(i >= n){
            return temp.size();
        }
        int include = 0, exclude = 0;

        if(hasDuplicate(arr[i],temp)){  // excludes only and check arr[i] first
            exclude = solve(arr, i+1, temp);
        }else {  // 2 options -> 1. exclude , 2. include
            exclude = solve(arr, i+1, temp);
            temp += arr[i];
            include = solve(arr, i+1, temp);
        }

        return max(include, exclude);
    }
    int maxLength(vector<string>& arr) {
        n = arr.size();
        string ans = "";
        return solve(arr,0,ans);
    }
};

int main(){
  Solution s;
  vector<string>arr{"un","iq","ue"};
  s.maxLength(arr);  
  return 0;
}
