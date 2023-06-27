#include <bits/stdc++.h> 

void findsubs(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans){
    ans.push_back(ds);

    for(int i=ind; i<nums.size(); i++){
        if(i != ind && nums[i]==nums[i-1]) continue;
        ds.push_back(nums[i]);
        findsubs(i+1, nums, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int>ds;
    sort(arr.begin(), arr.end());
    findsubs(0, arr, ds, ans);
    return ans;
}
