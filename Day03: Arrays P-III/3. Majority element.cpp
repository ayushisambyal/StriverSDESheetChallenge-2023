#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	
    // Moore's voting algo
    int ele, cnt = 0;
    
    for(int i=0; i<n; i++){
        if(cnt == 0){
            cnt = 1;
            ele = arr[i];
        }
        else if(arr[i] == ele) cnt++;
        else cnt--;
    }
    
    cnt = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == ele) cnt++;
    }
    if(cnt > n/2) return ele;
    return -1;
}
