#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<int>getNSL(vector<int>& arr, int n){
        vector<int>result(n);
        stack<int>st;
        for(int i = 0; i<n; i++){
            if(st.empty()){
                result[i] = -1;
            }else {
                while(!st.empty() && arr[st.top()] >= arr[i]){  // add duplicate
                    st.pop();
                }
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return result;
    }
    vector<int>getNSR(vector<int>& arr, int n){
        vector<int>result(n);
        stack<int>st;
        for(int i = n-1; i>=0; i--){
            if(st.empty()){
                result[i] = n;
            }else {
                while(!st.empty() && arr[st.top()] > arr[i]){ // remove duplicate
                    st.pop();
                }
                result[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return result;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>NSL = getNSL(arr,n); // left
        vector<int>NSR = getNSR(arr,n); // right

        long long sum = 0;
        int mod = 1e9 + 7;

        for(int i = 0; i < n; i++){
            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;
            long long totalWays = ls * rs; // no of subarrays

            long long totalSum = totalWays * arr[i];

            sum = (sum + totalSum) % mod;
        }

        return sum;
    }
};
int main(){
  Solution s;
  vector<int>arr{1,2,1,3,4,5,1};
  s.sumSubarrayMins(arr);
  return 0;
}
