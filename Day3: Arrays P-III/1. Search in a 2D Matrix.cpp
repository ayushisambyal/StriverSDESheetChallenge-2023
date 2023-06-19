bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size(); // no of rows
    int m = mat[0].size(); // no of columsn

    int low = 0;
    int high = (n*m)-1;

    while(low <= high){
        int mid = (low + (high - low)/2);

        if(mat[mid/m][mid%m] == target) return true;
        if(mat[mid/m][mid%m] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
