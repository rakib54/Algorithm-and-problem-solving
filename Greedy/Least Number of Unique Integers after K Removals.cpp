#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    static bool compare(const pair<int,int>&a, const pair<int,int>&b){
        return a.second < b.second;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;

        for(auto num: arr){
            mp[num]++;
        }
        vector<pair<int,int>>v;

        for(auto i: mp){
            v.push_back(i);
        }

        sort(v.begin(), v.end(), compare);
        int count = 0;
        for(auto num: v){
           if(num.second <= k){
               count++;
               k -= num.second;
           }
           if(k == 0) break;
        }

        return v.size() - count;

    }
};

int main(){
  Solution s;
  vector<int>nums{4,3,1,1,3,3,2};
  s.findLeastNumOfUniqueInts(nums, 3);
  return 0;
}
