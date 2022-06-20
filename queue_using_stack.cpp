#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    stack<int> st1,st2;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        st1.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(st1.empty()==true) return -1;
        while(st1.empty()==false){
            st2.push(st1.top());
            st1.pop();
        }
        int x=st2.top();
        st2.pop();
        while(st2.empty()==false){
            st1.push(st2.top());
            st2.pop();
        }
        return x;
    }

    int peek() {
        // Implement the peek() function here.
        if(st1.empty()==true) return -1;
        while(st1.empty()==false){
            st2.push(st1.top());
            st1.pop();
        }
        int x=st2.top();
        while(st2.empty()==false){
            st1.push(st2.top());
            st2.pop();
        }
        return x;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return st1.empty();
    }
};