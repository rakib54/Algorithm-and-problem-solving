#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();

        int first_half = 0, second_half = 0;
        for(int i = 0; i < n/2; i++){
            char c = tolower(s[i]);
            if(c == 'a' || c == 'e' ||c == 'i' ||c == 'o' || c == 'u'){
                first_half++;
            }
        }
        for(int i = n/2; i < n; i++){
            char c = tolower(s[i]);
            if(c == 'a' || c == 'e' ||c == 'i' ||c == 'o' || c == 'u'){
                second_half++;
            }
        }

        return first_half == second_half;
    }
};

int main(){
  Solution solution;
  solution.halvesAreAlike("book");
  return 0;
}
