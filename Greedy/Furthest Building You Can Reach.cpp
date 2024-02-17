#include <bits/stdc++.h>
using namespace std;
#define ll long long

// using min heap
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i = 0; i < n - 1 ; i++){
            int diff = heights[i+1] - heights[i];

            if(diff > 0){
                pq.push(diff);

                if(pq.size() > ladders){
                    int highest_diff = pq.top();

                    pq.pop();
                    bricks -= highest_diff;

                    if(bricks < 0){
                        return i;
                    }
                }
            }
        }
        return n-1;
    }
};


// using max heap
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int>pq; // max heap

        int i = 0; 

        for(; i < n - 1; i++){
            if(heights[i+1] <= heights[i]){
                continue;
            }
            
            int diff = heights[i+1] - heights[i];

            if(diff <= bricks){
                bricks -= diff;
                pq.push(diff);
            }
            else if(ladders > 0){
                if(!pq.empty()){
                    int max_bricks_past = pq.top();
                    if(max_bricks_past > diff){
                        bricks += max_bricks_past;
                        pq.pop();
                        pq.push(diff);
                        bricks -= diff;
                    }
                }
                ladders--;
            }
            else {
                break;
            }    
        }
        return i;
    }
};

int main(){
  Solution solution;
  vector<int>heights{4,12,2,7,3,18,20,3,19};
  int bricks = 10;
  int ladder = 2;
  solution.furthestBuilding(heights,bricks,ladder);
  
  return 0;
}

// problem link : https://leetcode.com/problems/furthest-building-you-can-reach/description/?envType=daily-question&envId=2024-02-17
