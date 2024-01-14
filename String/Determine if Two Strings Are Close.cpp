#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        vector<int>freq1(26);
        vector<int>freq2(26);

        for(int i=0;i<word1.size();i++){
            freq1[word1[i] -'a']++;
            freq2[word2[i] -'a']++;
        }

        // check element present or not in both freq array
        for(int i=0;i<26;i++){
            if(freq1[i] != 0 && freq2[i] != 0) continue;
            if(freq1[i] == 0 && freq2[i] == 0) continue;

            return false;
        }
        // match frequency
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
 

    }
};

int main(){
  Solution s;
  s.closeStrings("aba", "bba");
  return 0;
}
