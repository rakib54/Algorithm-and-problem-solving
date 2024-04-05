#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    string makeGood(string s) {
        stack<char>st;

        for(char &ch: s){
            if(st.empty()){
                st.push(ch);
            }
            else if(abs(ch - st.top()) == 32){
                st.pop();
            }
            else {
                st.push(ch);
            }
        }
        string ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
       
    }
};

int main(){
  Solution s;
  string str = "abBAcC";
  s.makeGood(str);
  return 0;
}
