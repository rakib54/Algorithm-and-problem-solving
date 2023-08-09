#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int n;
    bool isValid(int mid,int p,vector<int>&nums){
        int count = 0;
        int i = 0;
        
        while(i< n-1){
            if(nums[i+1] - nums[i] <= mid){
                count++;
                i+= 2;
            }
            else i++;
        }
        return count >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        n = nums.size();
        sort(begin(nums), end(nums));
        int low = 0, high = nums[n-1] - nums[0];
        int result;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(isValid(mid, p,nums)){
                result = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return result;
    }
};

int main(){
  Solution s;
  vector<int>nums {10,1,2,7,1,3};
  int p =2;
  cout<<s.minimizeMax(nums,p);

  return 0;
}
