#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int n = words.size();
        int result = 0;
        unordered_map<char,int>mp;

        for(char &ch: chars){
            mp[ch]++;
        }
        
        for(int i = 0;i<n; i++){
            string word = words[i];
            unordered_map<char,int>str;
            for(char &ch: word){
                str[ch]++;
            }

            bool flag = true;
            for(int i = 0; i<word.length(); i++){
                if(str[word[i]] > mp[word[i]]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                result += word.size();
            }
        }

        return result;
    }
};

int main(){
  Solution s;
  vector<string> words {"cat","bt","hat","tree"};
  string chars = "atach";
  s.countCharacters(words,chars);
  
  return 0;
}
