#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    bool solve(vector<char>&v, char exp){
        
        if(exp == '|'){
            for(char i: v){
                if(i == 't'){
                    return true;
                }
            }
            return false;
        }else if(exp == '&'){
            for(char i: v){
                if(i == 'f'){
                    return false;
                }
            }
            return true;
        }else {
            if(v[0] == 'f'){
                return true;
            }
            return false;
        }
    }
    bool parseBoolExpr(string expression) {
        stack<char>st;

        for(char &ch: expression){
            if(ch == ',') continue;
            if(ch == ')'){
                vector<char>v;
                while(!st.empty() && st.top() != '('){
                    v.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char exp = st.top();
                st.pop();

                bool status = solve(v, exp);
                st.push(status == false ? 'f' : 't');


            }else {
                st.push(ch);
            }
        }   

        return st.top() == 't';
    }
};

int main(){
  Solution solution;
  string expression = "!(&(f,t))";
  solution.parseBoolExpr(expression);
  
  return 0;
}
