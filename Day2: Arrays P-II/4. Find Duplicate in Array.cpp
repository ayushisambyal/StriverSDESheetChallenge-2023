#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	
	// Tortoise and Hare Algo
	int slow = arr[arr[0]];
    int fast = arr[arr[arr[0]]];
    
	while(slow!=fast){
        slow = arr[slow];
        fast = arr[arr[fast]];
    }

    fast=arr[0];
    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
