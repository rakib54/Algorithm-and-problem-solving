#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int getLucky(string s, int k) {
        string sum = "";

        for(char &ch: s){
            int digit = (ch - 'a') + 1;
            sum += to_string(digit);
        }

        while(k--){
            int digitSum = 0;
            for(char &ch: sum){
                int digit = ch - '0';
                digitSum += digit;
            }
            sum = to_string(digitSum);
        }

        return stoi(sum);
    }
};

int main(){
  Solution solution;
  string s="leetcode";
  int k = 2;

  solution.getLucky(s, k);
  return 0;
}
