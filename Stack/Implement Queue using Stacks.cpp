#include <bits/stdc++.h>
using namespace std;
#define ll long long

class MyQueue {
public:
    stack<int>input,output;
    int peekElement = -1;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()){
            peekElement = x;
        }
        input.push(x);
        
    }
    
    int pop() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int val = output.top();
        output.pop();

        return val;
    }
    
    int peek() {
        if(output.empty()){
            return peekElement;
        }
        return output.top();

    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

int main(){
  MyQueue myQueue;
  myQueue.push(1); // queue is: [1]
  myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
  myQueue.peek(); // return 1
  myQueue.pop(); // return 1, queue is [2]
  myQueue.empty(); // return false
  
  return 0;
}
