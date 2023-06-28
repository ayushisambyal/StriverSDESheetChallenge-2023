#include <bits/stdc++.h>

void findC(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
	if(target==0){
		ans.push_back(ds);
		return;
	}
	for(int i=ind; i<arr.size(); i++){
		if(i>ind && arr[i]==arr[i-1]) continue;
		// skipping duplicates
		if(arr[i]>target) break;
		ds.push_back(arr[i]);
		findC(i+1, target - arr[i], arr, ans, ds);
		ds.pop_back();
	}
}


vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;
	vector<int> ds;
	findC(0, target, arr, ans, ds);
	return ans;
}
