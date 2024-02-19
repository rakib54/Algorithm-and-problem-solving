#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;

        while(n% 2 == 0){
            n = n  / 2;
        }
        return n == 1;
    }
};

int main(){
  Solution s;
  s.isPowerOfTwo(16);  
  return 0;
}
