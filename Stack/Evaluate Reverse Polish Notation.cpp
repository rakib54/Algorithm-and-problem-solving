#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        int n = tokens.size();

        for(int i = 0; i < n; i++){

            if(tokens[i] == "+"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(first + second);
            }
            else if(tokens[i] == "-"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second - first);
            }
            else if(tokens[i] == "*"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(first * second);
            }
            else if(tokens[i] == "/"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second / first);
            }
            else {
                string s = tokens[i];
                int val = stoi(s);
                st.push(val);
            }
            
        }
        return st.top();

    }
};

int main(){
  Solution s;
  vector<string>tokens{"2","1","+","3","*"};
  s.evalRPN(tokens);
  return 0;
}
