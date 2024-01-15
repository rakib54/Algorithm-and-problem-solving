#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>mp;
        int n = matches.size();

        for(int i = 0; i<n; i++){
            int loser = matches[i][1];
            mp[loser]++;
        }

        set<int>no_lost,lost_one;

        for(int i = 0; i<n; i++){
            int winner = matches[i][0];
            int loser = matches[i][1];

            if(mp.find(winner) == mp.end()){
                no_lost.insert(winner);
            }
            if(mp.find(loser) != mp.end()){
                if(mp[loser] == 1){
                    lost_one.insert(loser);
                }
            }
        }
        vector<int>winner,onelost;
        for(auto i: no_lost){
            winner.push_back(i);
        }
        for(auto i: lost_one){
            onelost.push_back(i);
        }
        
        return {{winner}, {onelost}};
    }
};

int main(){
  Solution solution;
  vector<vector<int> >matches{{1,2}, {2,3},{1,4}, {3,2}};
  solution.findWinners(matches);
  
  return 0;
}
