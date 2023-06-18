#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	
	// adding elements of arr2 to arr1
	for(int i=0; i<n; i++){
        arr1[m+i]=arr2[i];
    }

	int len = n+m;
    int gap= (len/2) + (len%2);

    while(gap>=1){
        int left=0, right=left+gap;
        while(right<n+m){

            if(arr1[left] > arr1[right]){
                swap(arr1[left], arr1[right]);
            }
            left++; right++;
        }
		
        if(gap==1) break;
        gap=(gap+1)/2;
    }
    return arr1;    
}
