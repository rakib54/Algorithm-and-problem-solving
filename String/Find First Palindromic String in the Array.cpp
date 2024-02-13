#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    bool isPalindrome (string &word){
        int i = 0, j = word.size()-1;

        while(i <= j){
            if(word[i] == word[j]){
                i++;
                j--;
            }else {
                return false;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        string firstP;
        int n = words.size();

        for(int i = 0; i < n; i++){
            if(isPalindrome(words[i])){
                return words[i];
            }
        }

        return "";
    }
};

int main(){
  Solution s;
  vector<string> words{"abc","car","ada","racecar","cool"};
  s.firstPalindrome(words);  
  return 0;
}
