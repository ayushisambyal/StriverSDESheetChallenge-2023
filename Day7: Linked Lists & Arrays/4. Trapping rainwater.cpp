#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    
    long l=0, r=n-1, res=0;
    long lmax=INT_MIN, rmax=INT_MIN;

    while( l <= r ){
        if(arr[l] <= arr[r]){
            if(arr[l]>=lmax) lmax=arr[l];
            else res += lmax-arr[l];
            l++;
        }
        else{
            if(arr[r]>=rmax) rmax=arr[r];
            else res += rmax-arr[r];
            r--;
        }
    }
    return res;
}
