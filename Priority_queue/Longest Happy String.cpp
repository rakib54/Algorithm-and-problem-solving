#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>>pq;

        if(a > 0 )
            pq.push({a, 'a'});
        if(b > 0 )
            pq.push({b, 'b'});

        if(c > 0 )
            pq.push({c, 'c'});
        string result = "";

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            char ch = top.second;
            int currCount = top.first;

            // check last two char
            if(result.size() >= 2 && result[result.length() - 1] == ch && result[result.length() - 2] == ch){
                if(pq.empty()){
                    break;
                }
                int nextvalue = pq.top().first;
                char ch = pq.top().second;
                pq.pop();

                result += ch;
                nextvalue --;

                if(nextvalue > 0){
                    pq.push({nextvalue, ch});
                }

            }else {
                result += ch;
                currCount--;
            }
            if(currCount > 0){
                pq.push({currCount, ch});
            }
        }
        
        return result;
    }
};

int main(){
  Solution s;
  s.longestDiverseString(6,2,1);
  return 0;
}
