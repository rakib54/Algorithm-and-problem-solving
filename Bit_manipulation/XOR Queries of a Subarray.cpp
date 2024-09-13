#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>result;

        for(vector<int>&query: queries){
            int start = query[0];
            int end = query[1];
            int val = 0;
            for(int i = start; i <= end; i++){
                val = val ^ arr[i];
            }
            result.push_back(val);
        }

        return result;
    }
};

int main(){
  Solution s;
  vector<int>arr{1,3,4,8};
  vector<vector<int>>queries{{0,1},{1,2}, {0,3}, {3,3}};
  s.xorQueries(arr,queries);

  return 0;
}