#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        if(t.size() > n){
            return "";
        }

        unordered_map<char, int>mp;

        for(auto &ch: t){
            mp[ch]++;
        }

        int i =0 , j = 0;
        int requireCount = t.size();
        int min_windowSize = INT_MAX;
        int startIdx = 0;

        while(j < n){
            char ch = s[j];

            if(mp[ch] > 0){
                requireCount --;
            }
            mp[ch]--;

            while(requireCount == 0){
                int currWindowSize = j - i + 1;

                if(currWindowSize < min_windowSize){
                    min_windowSize = currWindowSize;
                    startIdx = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0){
                    requireCount++;
                }
                i++;
            }
            j++;
        }
        return min_windowSize == INT_MAX ? "": s.substr(startIdx, min_windowSize);
    }
};

int main(){
  Solution s;
  s.minWindow("ADOBECODEBANC","ABC");  // Answer = BANC
  return 0;
}
