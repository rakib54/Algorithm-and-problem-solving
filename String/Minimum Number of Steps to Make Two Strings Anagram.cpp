#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        unordered_map<char,int>mp;
        for(char &ch : s){
            mp[ch]++;
        }
        int count = 0;

        for(int i = 0; i<n; i++){
            if(mp.find(t[i]) != mp.end()){
                if(mp[t[i]] > 1){
                    mp[t[i]]--;
                }
                else {
                    mp.erase(t[i]);
                }
            }else {
                count++;
            }
        }

        return count;
    }
};

class Solution2 {
public:
    int minSteps(string s, string t) {
        int freq[26] = {0};
        for(char c: s){
            freq[c-'a']++;
        }
        for(char c: t){
            freq[c-'a']--;
        }
        int count = 0;

        for(int i = 0; i<26;i++){
            if(freq[i] > 0){
                count += freq[i];
            }
        }

        return count;
    }
};

int main(){
  Solution s;
  s.minSteps("aba", "bab");  
  return 0;
}
