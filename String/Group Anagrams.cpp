#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;

        for(string s: strs){
            string key = s; 
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        vector<vector<string>>result;

        for(auto str: mp){
            result.push_back(str.second);
        }

        return result;
    }
};

int main(){
  Solution s;
  vector<string> strs{"eat","tea","tan","ate","nat","bat"};
  s.groupAnagrams(strs);
  return 0;
}
