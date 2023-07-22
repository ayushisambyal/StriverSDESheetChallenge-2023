#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    vector<int> ans;
    stack<pair<int, int>> st;

    for(auto i : price){
        int span = 1;

        while(!st.empty() && i >= st.top().first){
            span += st.top().second;
            st.pop();
        }
        st.push({i, span});
        ans.push_back(span);
    }
    return ans;
}
