#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &a, int n) {
    vector<int> nge(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] < a[i]) {
            nge[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }

    // Process remaining elements in the stack
    while (!st.empty()) {
        nge[st.top()] = -1;
        st.pop();
    }

    return nge;
}
