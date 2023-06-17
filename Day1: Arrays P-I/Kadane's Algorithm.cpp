#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long int currsum=0;
    long long int sum=0;

    for(int i=0; i<n; i++){
        currsum += arr[i];

        if(currsum < 0) currsum = 0;
        sum = max(sum, currsum);
    }
    return sum;
}
