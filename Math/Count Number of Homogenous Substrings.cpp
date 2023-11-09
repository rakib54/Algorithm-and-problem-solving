#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    const int MOD = 1e9 + 7;
    int countHomogenous(string s) {
        int n = s.size();
        
        long long ans = 0;
        int count = 0;
        for(int i= 0; i< n; i++){
            count++;
            ans += count;
            
            if(s[i] != s[i+1]){
                count = 0;
            }
        }

        return ans % MOD;
    }
};

int main(){
  Solution solution;
  solution.countHomogenous("abbcccaa");
  return 0;
}
