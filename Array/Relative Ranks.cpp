#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int,int>mp;
        int n = score.size();
        vector<int>store(score.begin(), score.end());

        sort(score.rbegin(), score.rend());

        for(int i = 0; i < n; i++){
            mp[score[i]] = i + 1;
        }

        vector<string>answer;

        for(int num: store){
            if(mp[num] == 1){
                answer.push_back("Gold Medal");
            }
            else if(mp[num] == 2){
                answer.push_back("Silver Medal");
            }
            else if(mp[num] == 3){
                answer.push_back("Bronze Medal");
            }
            else {
                answer.push_back(to_string(mp[num]));
            }
        }

        return answer;
    }
};

int main(){
  Solution s;
  vector<int>score{10,3,8,9,4};
  s.findRelativeRanks(score);
  return 0;
}
