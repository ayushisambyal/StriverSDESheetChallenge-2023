#include <bits/stdc++.h>

void insertAt(stack<int> &s,int temp){
    if(s.empty() || s.top() < temp) {
        s.push(temp);
        return;
    }
    int temp2= s.top();
    s.pop();
    insertAt(s,temp);
    s.push(temp2);
}


void sortStack(stack<int> &s)
{
    if(s.size()<=1) return;
    int temp= s.top();
    s.pop();
    sortStack(s);
    insertAt(s, temp);
    return;
}
