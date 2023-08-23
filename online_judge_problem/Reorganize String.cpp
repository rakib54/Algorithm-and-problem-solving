#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        vector<int>count(26,0);

        for(char ch: s){
            count[ch-'a']++;

            if(count[ch-'a'] > (n+1)/2){
                return "";
            }
        }


        priority_queue<pair<int,char>>pq;

        for(char c = 'a'; c<='z'; c++){
            if(count[c-'a'] > 0){
                pq.push({count[c-'a'], c});
            }
        }
        string ans = "";

        while(pq.size() >= 2){
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();

            ans += p1.second; p1.first--;
            ans += p2.second; p2.first--;

            if(p1.first > 0 ){
                pq.push(p1);
            }
            if(p2.first > 0 ){
                pq.push(p2);
            }
        }
        if(!pq.empty()){
            ans += pq.top().second;
        }
        
        return ans;
    }
};

int main(){
  Solution solution;
  solution.reorganizeString("aab")
 
  return 0;
}
