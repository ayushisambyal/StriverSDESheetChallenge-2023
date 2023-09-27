#include <queue>
#include <vector>

bool check (int start, vector<int> adj[], int color[]){
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto x : adj[node]){
            if(color[x] == -1){
                color[x] = !color[node];
                q.push(x);
            }
            else if(color[x] == color[node]) return false;
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	int v = edges.size();
    vector<int> adj[v + 1];
    
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (edges[i][j] == 1) {
                adj[i + 1].push_back(j + 1);
                adj[j + 1].push_back(i + 1);
            }
        }
    }

    
    int color[v + 1];
    for (int i = 1; i <= v; i++) color[i] = -1;
        for(int i=0; i<v; i++){
        if(color[i] == -1){
            if(check(i, adj, color)==false)
                return false;
        }
    }
    
    return true;
}
