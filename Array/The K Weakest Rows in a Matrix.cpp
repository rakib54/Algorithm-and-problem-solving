#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int binary_search(vector<int>&mat){
        int low = 0, high = mat.size()-1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(mat[mid] == 1){
                low = mid + 1;
            }
            else {
                high = mid -1;
            }
        }
        return low;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();

        priority_queue<pair<int,int>>pq;
        for(int i=0;i <n; i++){
            int count = binary_search(mat[i]);
            pq.push({count, i});

            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<int>ans(k);
        int i = k-1;
        while(!pq.empty()){
            ans[i] = pq.top().second;
            pq.pop();
            i--;
        }

        return ans;
        
    }
};

int main(){
  Solution s;
  vector<vector<int>>mat {{1,1,0,0,0}, {1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};

  s.kWeakestRows(mat,3);
  return 0;
}
