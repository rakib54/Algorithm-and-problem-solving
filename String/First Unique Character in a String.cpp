#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        vector<int>v(26, 0);

        for(char &ch: s){
            v[ch-'a']++;
        }
        int idx = -1;

        for(int i = 0; i< n; i++){
            if(v[s[i] - 'a'] == 1){
                return i;
            }
        }
        return idx;
    }
};

int main(){
  Solution s;
  s.firstUniqChar("Leetcode");  
  return 0;
}
