#include <bits/stdc++.h>
class Stack {
	// Define the data members.
    queue<int> q;

   public:
    Stack() {
    }
    int getSize() {
        return q.size();
    }

    bool isEmpty() {
        return q.empty();
    }

    void push(int element) {
        int n= q.size();
        q.push(element);

        for(int i=0; i<n; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if(q.empty()) return -1;
        int ans=q.front();
        q.pop();
        return ans;
    }

    int top() {
        return q.empty() ? -1 : q.front();
    }
};
