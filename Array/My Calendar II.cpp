#include <bits/stdc++.h>
using namespace std;
#define ll long long

class MyCalendarTwo
{
public:
  vector<pair<int, int>> doubleBookingRegion;
  vector<pair<int, int>> overallBooking;

  pair<int, int> findOverlappedRegion(int start1, int end1, int start2, int end2)
  {
    return {max(start1, start2), min(end1, end2)};
  }

  bool checkOverlap(int start1, int end1, int start2, int end2)
  {
    return max(start1, start2) < min(end1, end2);
  }

  MyCalendarTwo()
  {
  }

  bool book(int start, int end)
  {
    // check if triple booking is created or not
    for (pair<int, int> region : doubleBookingRegion)
    {
      if (checkOverlap(region.first, region.second, start, end))
      {
        return false;
      }
    }
    // check if it created double booking

    for (pair<int, int> booking : overallBooking)
    {
      if (checkOverlap(booking.first, booking.second, start, end))
      {
        doubleBookingRegion.push_back(findOverlappedRegion(booking.first, booking.second, start, end));
      }
    }
    overallBooking.push_back({start, end});

    return true;
  }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

int main()
{

  return 0;
}
