#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &a, int n)
{
	// xor method
	int xr = 0;
	for(int i=0; i<n; i++){
		xr = xr ^ a[i];
		xr = xr ^ (i+1); // for xoring nos. 1 - n
	}
	
	// find the differentiating bit no.
	int bitNo = 0;
	while(1){
		if((xr & (1<<bitNo)) != 0){
			break;
		}
		bitNo++;
	}
	
	// create two buckets(ints) to seggregate all the nos. from array and 1-n
	// also xoring all elements
	int zero = 0, one = 0;
	for(int i=0; i<n; i++){
		
		// part of oneth club
		if( (a[i] & (1<<bitNo)) != 0){
			one ^= a[i];
		}
		// part of zeroth club
		else{
			zero ^= a[i];
		}
	}

	// repeating but for numbers from 1 to n
	for(int i=1; i<=n; i++){
		
		// part of oneth club
		if( (i & (1<<bitNo)) != 0){
			one = one ^ i;
		}
		// part of zeroth club
		else{
			zero = zero ^ i;
		}
	}
	
	// checking which one of the two nos. is missing and repeating
	int count = 0;
	for(int i=0; i<n; i++){
		if(a[i] == zero) return {one, zero};
	}
	return {zero, one};
}
