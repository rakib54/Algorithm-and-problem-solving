#include <bits/stdc++.h>
using namespace std;
#define ll long long

class MyCalendar
{
public:
  set<pair<int, int>> st;
  MyCalendar()
  {
  }

  bool book(int start, int end)
  {
    auto it = st.lower_bound({start, end});

    if (it != st.end() && it->first < end)
    { // check next element return >= start
      return false;
    }

    // check prev element
    if (it != st.begin())
    {
      auto prevIt = prev(it);
      if (prevIt->second > start)
      {
        return false;
      }
    }

    st.insert({start, end});

    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main()
{

  return 0;
}
