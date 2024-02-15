#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    void computeLPS(string &pat, vector<int>&LPS){
        int n = pat.size();
        int len = 0;
        int i = 1;
        LPS[0] = 0;

        while(i < n){
            if(pat[i] == pat[len]){
                len++;
                LPS[i] = len;
                i++;
            }
            else {
                if(len != 0){
                    len = LPS[len-1]; // len = len - 1 will also work
                }
                else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }

    int KMP(string &txt, string &pat,vector<int>&LPS){
        int n = txt.size();
        int m = pat.size();
        int i = 0, j = 0;
        int count = 0;

        while(i < n){
            if(txt[i] == pat[j]){
                i++;
                j++;
            }
            if(j == m){  // found pattern
                count++; 
                j = LPS[j-1];
            }
            else if(i < n && txt[i] != pat[j]){
                if(j != 0){
                    j = LPS[j-1];
                }else{
                    i++;
                }
            }
        }
        return count;
    }

    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int m = pattern.size();
        int n = nums.size();
        string s = "";
        
        for(int i = 0; i < n - 1; i++){
           if(nums[i+1] > nums[i]){
               s+= 'A';
           } 
           else if(nums[i+1] == nums[i]){
               s+= 'B';
           } 
           else if(nums[i+1] < nums[i]){
               s+= 'C';
           } 
        }
        string p = "";

        for(int i: pattern){
            if(i == 1){
                p+= 'A';
            }
            if(i == 0){
                p+= 'B';
            }
            if(i == -1){
                p+= 'C';
            }
        }

        vector<int>LPS(m, 0);
        computeLPS(p,LPS);
        return KMP(s,p,LPS);
    }
};

int main(){
  Solution s;
  vector<int>nums{1,4,4,1,3,5,5,3};
  vector<int>pattern{1,0,-1};
  s.countMatchingSubarrays(nums,pattern);
  return 0;
}
