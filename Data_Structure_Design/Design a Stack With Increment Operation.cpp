#include <bits/stdc++.h>
using namespace std;
#define ll long long

class CustomStack
{
public:
  stack<int> st;
  vector<int> v;
  int n;
  CustomStack(int maxSize)
  {
    n = maxSize;
  }

  void push(int x)
  {
    if (st.size() == n)
    {
      return;
    }
    st.push(x);
  }

  int pop()
  {
    if (st.empty())
    {
      return -1;
    }
    int top = st.top();
    st.pop();

    return top;
  }

  void increment(int k, int val)
  {
    int skip = st.size() - k;

    while (!st.empty())
    {
      int top = st.top();
      if (skip > 0)
      {
        v.push_back(top);
      }
      else
      {
        top = top + val;
        v.push_back(top);
      }
      st.pop();
      skip--;
    }

    reverse(v.begin(), v.end());

    for (auto ele : v)
    {
      st.push(ele);
    }
    vector<int> a;
    v = a;
  }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

int main()
{

  return 0;
}
