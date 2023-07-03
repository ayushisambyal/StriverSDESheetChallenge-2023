#include <bits/stdc++.h> 

void f(int ind, string &s, vector<string> &ans){
    // base case
    if(ind == s.size()){
        ans.push_back(s);
        return;
    }

    for(int i=ind; i<s.size(); i++){
        swap(s[i], s[ind]);
        f(ind+1, s, ans);
        swap(s[i], s[ind]);
    }
}
 
vector<string> findPermutations(string &s) {
    vector<string> ans;
    f(0, s, ans);
    return ans;
}
