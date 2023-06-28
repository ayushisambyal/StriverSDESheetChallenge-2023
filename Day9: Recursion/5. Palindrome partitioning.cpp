#include <bits/stdc++.h>

bool isPalindrome(string &S, int s, int e){
    while(s <= e){
        if(S[s++] != S[e--]) return 0;
    }
    return 1;
}

void f(int ind, string &s, vector<string> &ds, vector<vector<string>> &res){
    if(ind==s.size()){
        res.push_back(ds);
        return;
    }
    for(int i=ind; i<s.size(); i++){
        if(isPalindrome(s, ind, i)){
            ds.push_back(s.substr(ind, i-ind+1));
            f(i+1, s, ds, res);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> ans;
    vector<string> ds;
    f(0, s, ds, ans);
    return ans;
}
