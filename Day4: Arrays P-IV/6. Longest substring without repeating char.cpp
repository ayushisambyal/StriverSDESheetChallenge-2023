#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    vector<int> mp(256, -1);
    int n = s.size(), r = 0, l = 0, len = 0;
    
    while(r < n){
        if(mp[s[r]] != -1)
            l = max(mp[s[r]]+1, l);
        mp[s[r]] = r;
        len = max(len, r-l+1);
        r++;
    }
    return len;
}
