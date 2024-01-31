#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n , 0);
        stack<int>st;

        for(int i = n-1; i >=0 ; i--){
            int curr = temperatures[i];
            while(!st.empty() && curr >= temperatures[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};

int main(){
  Solution s;
  vector<int>temperatures{73,74,75,71,69,72,76,73};
  s.dailyTemperatures(temperatures);  
  return 0;
}
