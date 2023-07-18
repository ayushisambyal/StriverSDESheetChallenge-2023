#include<bits/stdc++.h>
using namespace std;

// largest one uses minHeap
int largest(vector<int> &arr, int k){
	priority_queue<int, vector<int>, greater<int>> minHeap;
	
	for(int i=0; i<k; i++){
		minHeap.push(arr[i]);
	}
	for(int i=k; i<arr.size(); i++){
		if(minHeap.top()<(arr[i])){
			minHeap.pop();
			minHeap.push(arr[i]);
		}
	}
	return minHeap.top();
}

int smallest(vector<int> &arr, int k){
	priority_queue<int> maxHeap;

	for (int i = 0; i < k; i++) {
		maxHeap.push(arr[i]);
	}
	for(int i=k; i<arr.size(); i++){
		if(maxHeap.top()>arr[i]){
			maxHeap.pop();
			maxHeap.push(arr[i]);
		}
	}
	return maxHeap.top();
}

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	vector<int> res;

	res.push_back(smallest(arr,k));
	res.push_back(largest(arr,k));

	return res;

}
