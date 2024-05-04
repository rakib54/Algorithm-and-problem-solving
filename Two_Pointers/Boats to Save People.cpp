#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int noOfBoats = 0;

        int  i =0 , j = n - 1;

        while( i <= j){
            if(people[i] + people[j] <= limit){
                i++;
            }
            noOfBoats++;
            j--;
        }

        return noOfBoats;
    }
};

int main(){
  Solution solution;
  vector<int>nums{5,1,4,2};
  int limit = 6;

  solution.numRescueBoats(nums,limit);
  return 0;
}
