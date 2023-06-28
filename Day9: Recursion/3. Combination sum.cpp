void findC(int ind, int target, vector<vector<int>> &ans, vector<int> &arr, vector<int> &ds){
    if(ind == arr.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }
    if(arr[ind] <= target){
        ds.push_back(arr[ind]);
        findC(ind, target-arr[ind], ans, arr, ds);
        ds.pop_back();
    }
    findC(ind+1, target, ans, arr, ds);
}

vector<vector<int>> combSum(vector<int> &arr, int B)
{
    vector<int> ds;
    vector<vector<int>> ans;
    findC(0, B, ans, arr, ds);
    return ans;
}
