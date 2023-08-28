#include <bits/stdc++.h>
using namespace std;
#define ll long long

class MyStack
{
public:
  MyStack()
  {
  }
  queue<int> q;

  void push(int x)
  {
    q.push(x);
    int size = q.size();
    while (size--)
    {
      q.push(q.front());
      q.pop();
      if (size == 1)
        break;
    }
  }

  int pop()
  {
    int result = q.front();
    q.pop();
    return result;
  }

  int top()
  {
    return q.front();
  }

  bool empty()
  {
    return q.empty();
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{

  return 0;
}
