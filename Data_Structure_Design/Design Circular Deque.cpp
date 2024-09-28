#include <bits/stdc++.h>
using namespace std;
#define ll long long

class MyCircularDeque
{
public:
  vector<int> deq;
  int currCount = 0;
  int front = 0;
  int rear;
  int K;
  MyCircularDeque(int k)
  {
    deq.resize(k);
    rear = k - 1;
    K = k;
  }

  bool insertFront(int value)
  {
    if (currCount == K)
    {
      return false;
    }
    front = (front - 1 + K) % K;
    deq[front] = value;

    currCount++;
    return true;
  }

  bool insertLast(int value)
  {
    if (currCount == K)
    {
      return false;
    }
    rear = (rear + 1) % K;
    deq[rear] = value;
    currCount++;
    return true;
  }

  bool deleteFront()
  {
    if (currCount == 0)
    {
      return false;
    }
    deq[front] = -1;
    front = (front + 1) % K; // move forward
    currCount--;
    return true;
  }

  bool deleteLast()
  {
    if (currCount == 0)
    {
      return false;
    }
    deq[rear] = -1;
    rear = (rear - 1 + K) % K; // move backward
    currCount--;
    return true;
  }

  int getFront()
  {
    if (currCount == 0)
    { // is empty
      return -1;
    }
    return deq[front];
  }

  int getRear()
  {
    if (currCount == 0)
    {
      return -1;
    }
    return deq[rear];
  }

  bool isEmpty()
  {
    return currCount == 0;
  }

  bool isFull()
  {
    return currCount == K;
  }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main()
{

  return 0;
}
