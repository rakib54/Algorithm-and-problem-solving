#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        for(int i = 0; i < s.size(); i++){

            // memory compare between two string
            if(!memcmp(s.c_str(), rev.c_str() + i, s.length() - i)){
                return rev.substr(0, i) + s;
            }
        }      
        return rev + s;    
    }
};

int main(){

  Solution s;
  s.shortestPalindrome("abcd");
  
  return 0;
}
