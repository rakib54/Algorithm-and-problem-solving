#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    typedef pair<long long, int>P;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<int>roomUsedCount(n, 0);

        priority_queue<P, vector<P>, greater<P>>usedRooms; // min heap
        priority_queue<int, vector<int>, greater<int>>availavleRooms;

        for(int i = 0; i < n; i++){
            availavleRooms.push(i);
        }

        for(vector<int>&meet: meetings){
            int start = meet[0];
            int end = meet[1];
            int duration = end - start;

            while(!usedRooms.empty() && usedRooms.top().first <= start){
                int room = usedRooms.top().second;
                availavleRooms.push(room);
                usedRooms.pop(); // remove form the usedRooms
            }

            if(!availavleRooms.empty()){
                int room = availavleRooms.top();
                availavleRooms.pop();
                usedRooms.push({end, room});
                roomUsedCount[room]++;
            }
            else {  // no room available
                int room = usedRooms.top().second;
                long long endTime = usedRooms.top().first;
                usedRooms.pop();
                usedRooms.push({endTime + duration, room});
                roomUsedCount[room]++;
            }
        }

        int mostUsedRoom = -1;
        int currMaxUsed = 0;

        for(int i = 0; i < n; i++){
            if(roomUsedCount[i] > currMaxUsed){
                currMaxUsed = roomUsedCount[i];
                mostUsedRoom = i;
            }
        }

        return mostUsedRoom;
    }
};

int main(){
  Solution s;
  vector<vector<int>>meetings{{0,10}, {1,5}, {2,7}, {3,4}};
  s.mostBooked(2,meetings);
  return 0;
}
