#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char, int>freq;

        for(char &ch: s){
            freq[ch]++;
        }

        for(auto i: freq){
            pq.push({i.second, i.first});  
        }

        string ans;

        while(!pq.empty()){
            auto ele = pq.top();
            for(int i = 0; i<ele.first; i++){
                ans.push_back(ele.second);
            }
            pq.pop();
        }

        return ans;
    }
};

int main(){
  Solution s;
  s.frequencySort("tree");
  return 0;
}
