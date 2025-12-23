#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> inStack;
    stack<int> outStack;

    MyQueue() {
        // constructor
    }
    
    // Push element x to the back of queue
    void push(int x) {
        inStack.push(x);
    }
    
    // Removes the element from the front of queue and returns it
    int pop() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int front = outStack.top();
        outStack.pop();
        return front;
    }
    
    // Get the front element
    int peek() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }
    
    // Returns whether the queue is empty
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
