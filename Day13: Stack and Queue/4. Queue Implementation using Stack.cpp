#include <bits/stdc++.h>

class Queue {
    // Define the data members(if any) here.
    stack<int> input;
    stack<int> output;

public:
    Queue() {
    }

    void enQueue(int val) { // push
        input.push(val);
    }

    int deQueue() { // pop
        if(!output.empty()){
            int ans = output.top();
            output.pop();
            return ans;
        }
        if(input.empty()) return -1;
        while(input.size()!=1){
            output.push(input.top());
            input.pop();
        }
        int ans=input.top();
        input.pop();
        return ans;
    }

    int peek() { // top
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.empty() ? -1 : output.top();
    }

    bool isEmpty() {
        return input.empty() && output.empty();
    }
};
