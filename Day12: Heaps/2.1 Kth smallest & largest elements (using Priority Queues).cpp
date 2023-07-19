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


/*
THIS IS ALSO VALID 

#include <bits/stdc++.h> 

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	priority_queue<int>pq;
    vector<int>v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pq.push(a[i]+b[j]);
        }
    }
    for(int i=0;i<k;i++){
        int a=pq.top();
        pq.pop();
        v.push_back(a);
    }
    return v;
} 
 
 */
