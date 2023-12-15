#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>mp;
        string ans;

        for(auto path: paths){
            string start = path[0];
            mp[start]++;
        }

        for(auto &path: paths){
            string destination = path[1];

            if(mp.find(destination) == mp.end()){
                ans = destination;
            }
        }
        return ans;
    }
};

int main(){
  Solution solution;
  vector<vector<string>>paths{{"London","New York"}, {"New York","Lima"},{"Lima","Sao Paulo"}};
  solution.destCity(paths);  
  return 0;
}
