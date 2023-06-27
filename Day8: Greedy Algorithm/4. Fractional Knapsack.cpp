#include <bits/stdc++.h> 

// comparing the val /wt ratio
bool comp(pair<int, int> p1, pair<int, int> p2){
    return p1.second/ (double)p1.first > p2.second/ (double) p2.first;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w){
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), comp);
    double ans = 0.0;
    for (auto it : items){
        
        if(w == 0) return ans;
        else{
            ans += min(w, it.first) * (it.second/ (double) it.first);
            w -= min (it.first, w);
        }
    }
    return ans;
}
