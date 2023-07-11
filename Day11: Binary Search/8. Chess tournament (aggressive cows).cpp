#include <bits/stdc++.h> 

bool ispossible(vector<int> &arr, int minD, int c){
	int cnt = 1, lastposition = arr[0];

	for(int i=0; i<arr.size(); i++){
		if(arr[i] -lastposition >= minD){
			cnt++;
			lastposition = arr[i];
		}
		if(cnt >= c) return 1;
	}
	return 0;
}

int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(), positions.end());
	int low = 0, high = positions[n-1] - positions[0];

	while(low <= high){
		int mid = (low + high) /2;
		if(ispossible(positions, mid, c) == 1){
			int ans = mid;
			low = mid+1;
		}
		else high = mid-1;
	}
	return high;
}
