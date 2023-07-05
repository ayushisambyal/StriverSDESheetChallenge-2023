bool isSafe(int node, int color[], vector<vector<int>> &mat, int n, int col){
    for(int i=0; i<n; i++){
        if(i != node && mat[i][node] == 1 && color[i] == col){
            return false;
        }
    }
    return true;
}

bool f(int node, int color[], int m, int n, vector<vector<int>> &mat){
    // base case
    if(node == n) return true;
    
    for(int i=1; i<=m; i++){
        if(isSafe(node, color, mat, n ,i)){
            color[node] = i;
            if(f(node+1, color, m, n, mat)) return true;
            color[node] = 0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    int color[n] = {0};
    if(f(0, color, m, n, mat)) return "YES";
    return "NO";
}
