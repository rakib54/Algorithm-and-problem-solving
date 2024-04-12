#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>leftMax(n, 0);
        vector<int>rightMax(n, 0);
        int leftMaxHeight = -1;
        int rightMaxHeight = -1;

        for(int i = 0; i < n; i++){
            leftMaxHeight = max(leftMaxHeight, height[i]);
            leftMax[i] = leftMaxHeight;
        }
        for(int i = n-1; i >= 0; i--){
            rightMaxHeight = max(rightMaxHeight, height[i]);
            rightMax[i] = rightMaxHeight;
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }

        return ans;

    }
};

int main(){
  Solution s; 
  vector<int>height{};
  s.trap(height);
  return 0;
}
