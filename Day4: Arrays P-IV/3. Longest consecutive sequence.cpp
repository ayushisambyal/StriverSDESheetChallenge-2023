#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n) {
    
    if(n==0) return 0;
    int longest = 1;
    unordered_set<int> s;

    for(auto it : nums){
        s.insert(it);
    }

    for(auto it : s){
        if(s.find(it - 1) == s.end()){
            int cnt = 1, x = it;
            while(s.find(x+1) != s.end()){
                x++; cnt++;
            }
            longest = max(longest, cnt);
        }
    }

    return longest;
}
