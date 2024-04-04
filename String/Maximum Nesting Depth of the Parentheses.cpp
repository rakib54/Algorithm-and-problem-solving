#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int count = 0, result = 0;

        for(int i =0; i < n; i++){
            if(s[i] == '('){
                count++;
            }
            else if(s[i] == ')'){
                count--;
            }

            result = max(result, count);
        }

        return result;
    }
};

int main(){
  Solution s;
  string str = "(1)+((2))+(((3)))";
  s.maxDepth(str);  
  return 0;
}
