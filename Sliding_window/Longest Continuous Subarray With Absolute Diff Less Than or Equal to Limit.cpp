#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    typedef pair<int,int>P;
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        priority_queue<P>maxPq;
        priority_queue<P, vector<P>, greater<P>>minPq;

        int i = 0, j = 0;
        int maxLength = 0;

        while(j < n){
            maxPq.push({nums[j], j});
            minPq.push({nums[j], j});

            while(maxPq.top().first - minPq.top().first > limit){
                i = min(maxPq.top().second, minPq.top().second) + 1; // shrink the window
                while(maxPq.top().second < i){
                    maxPq.pop();
                }
                while(minPq.top().second < i){
                    minPq.pop();
                }
            }

            maxLength = max(maxLength, j - i + 1);
            j++;
        }

        return maxLength;
    }
};

int main(){
  vector<int>nums{8,2,4,7};
  int limit = 4;
  
  Solution solution;
  solution.longestSubarray(nums,limit);
  return 0;
}
