#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>freq(101,0);

        int maxF = 0;
        for(int i = 0; i < nums.size(); i++){
           freq[nums[i]]++;
           maxF = max(maxF, freq[nums[i]]);

        }

        int result = 0;
        for(int i = 1; i <= 100; i++){
            if(freq[i] == maxF){
                result += freq[i];
            }
        }

        return result;
    }
};
int main(){
  Solution s;
  vector<int>nums{1,2,3,1,2,6};
  s.maxFrequencyElements(nums);
  return 0;
}
