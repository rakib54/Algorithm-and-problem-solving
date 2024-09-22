#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int Count(long curr, long next, int n){
        int countNum= 0;

        while(curr <= n){
            countNum += (next - curr);
            curr *= 10;
            next *= 10;
            next = min(next, long(n + 1));
        }

        return countNum;
    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1; // since we start from 1 and we need k - 1 more numbers

        while(k > 0){
            int count = Count(curr, curr + 1, n);

            if(count <= k){
                curr++;
                k -= count;  // skipping numbers under curr prefix
            }else {
                curr *= 10; // going deep -> 1 -> 10 -> 100
                k -= 1;
            }
        }

        return curr;
    }
};

int main(){
  Solution s;
  s.findKthNumber(14,4);
  
  return 0;
}
