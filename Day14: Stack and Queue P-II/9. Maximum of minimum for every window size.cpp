#include <bits/stdc++.h>
vector<int> maxMinWindow(vector<int> a, int n) {
    //find the span of each element 
    //find the size in which it is minimum element and 
    //update the value accordingly.
    vector<int> left(n,-1),right(n,n);
    stack<int> lef, rig;
    lef.push(0);
    for(int i=1; i<n; i++){
        while(!lef.empty() && a[lef.top()]>=a[i]){
            lef.pop();
        }
        if(!lef.empty()) left[i]=lef.top();
        lef.push(i);
    }
    rig.push(n-1);
    for(int i=n-2; i>=0; i--){
        while(!rig.empty() && a[rig.top()]>=a[i]){
            rig.pop();
        }
        if(!rig.empty()) right[i]=rig.top();
        rig.push(i);
    }
    vector<int> ans(n,INT_MIN);
    for(int i=0; i<n; i++){
        ans[right[i]-left[i]-2]=max(ans[right[i]-left[i]-2], a[i]);
    }
    //-2 for zero based
    for(int i=n-2; i>=0; i--){
        ans[i]=max(ans[i],ans[i+1]);
    }
    return ans;
}
