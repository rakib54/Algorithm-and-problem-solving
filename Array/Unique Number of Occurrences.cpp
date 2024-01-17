#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto ele: arr){
            mp[ele]++;
        }
        vector<int>v;
        for(auto i: mp){
            v.push_back(i.second);
        }

        sort(v.begin(), v.end());

        for(int i = 0; i < v.size()-1; i++){
            if(v[i] == v[i+1]){
                return false;
            }
        }
        return true;
    }
};

int main(){
  Solution s;
  vector<int>arr{1,2,1,1,1};
  s.uniqueOccurrences(arr);  
  return 0;
}
