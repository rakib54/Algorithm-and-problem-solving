#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
    public:
        void computeLPS(string &pat, vector<int>&LPS, int M){
            int len = 0; // len of prev longest prefix and suffix were equal
            
            LPS[0] = 0;
            int i = 1;
            
            while(i < M){
                if(pat[i] == pat[len]){
                    len++;
                    LPS[i] = len;
                    i++;
                }else {
                    if(len != 0){
                        len = LPS[len-1];
                    }else {
                        LPS[i] = 0;
                        i++;
                    }
                }
            }
        }
        
        vector <int> search(string pat, string txt)
        {
            int N = txt.length();
            int M = pat.length();
            
            vector<int>ans;
            
            // create lPS array to check longest prefix and suffix equal length
            vector<int>LPS(M, 0);
            
            computeLPS(pat,LPS, M);
            
            int i = 0, j = 0;
            
            while(i < N){
                if(txt[i] == pat[j]){
                    i++;
                    j++;
                }
                if(j == M){
                    ans.push_back(i- M +1);
                    j = LPS[j-1];
                }
                else if(i < N && txt[i] != pat[j]) {
                    if(j != 0){
                        j = LPS[j-1];
                    }else {
                        i++;
                    }
                }
            }
            
            return ans;
        }
     
};

int main(){
  
  return 0;
}
