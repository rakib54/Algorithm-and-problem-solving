#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int n = students.size();
        
        int moves = 0;

        for(int i = 0; i < n; i++){
            moves += abs(students[i] - seats[i]);
        }
        
        return moves;
    }
};

int main(){
  Solution s;
  vector<int>seats{3,1,5};
  vector<int>students{2,7,4};

  s.minMovesToSeat(seats, students);
  return 0;
}
