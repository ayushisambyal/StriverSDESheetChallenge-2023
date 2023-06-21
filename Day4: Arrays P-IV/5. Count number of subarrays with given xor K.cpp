#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int k)
{
    int xr = 0;
    map<int, int> mp;
    mp[xr]++; // initialised with {0,1}

    int len = 0;
    for(int i=0; i<arr.size(); i++){
        xr = xr ^ arr[i];
        int x = xr ^ k;
        len += mp[x];
        mp[xr]++;
    }
    return len;
}
