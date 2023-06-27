#include <bits.c++/h>

fxn(int idx, int sum, vector<int> arr, int N, vector<int> ans){
	if(idx == N)
		ans.push_back(sum);
		return;
	// pick
	fxn(idx+1, sum+arr[idx], arr, N, ans);
	// not pick
	fxn(idx+1, sum, arr, N, ans);
}

vector<int> subsetSum(vector<int> &num){
	vector<int> ans;
	fxn(0, 0, num, num.size(), ans);
	sort(ans.begin(), ans.end());
	return sums;	
}
