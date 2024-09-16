#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();

        vector<int>minutes(n);

        for(int i = 0; i < n; i++){
            int hr = stoi(timePoints[i].substr(0,2));
            int min = stoi(timePoints[i].substr(3));

            minutes[i] = hr * 60 + min;
        }

        sort(minutes.begin(), minutes.end());

        int minDiff = INT_MAX;

        for(int i = 0; i < n-1; i++){
            minDiff = min(minDiff, minutes[i+1] - minutes[i]);
        }

        minDiff = min(minDiff, 24 * 60 - minutes.back() + minutes.front());

        return minDiff;
    }
};

int main(){
  Solution s;
  vector<string>timePoints{"23:59","00:00"};
  s.findMinDifference(timePoints);
  return 0;
}
