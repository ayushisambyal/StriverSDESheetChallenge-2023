#include <bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<int> adj[n+1];
    vector<int> indegree(n+1);
    for(auto p : edges){
        adj[p.first].push_back(p.second);
        indegree[p.second]++;
    }
    queue<int> q;
    for(int i=1; i<n+1; i++){
        if(indegree[i]==0) q.push(i);
    }
    int cnt=0;
    while(!q.empty()){
        int node= q.front();
        for(auto i : adj[node]){
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
        q.pop();
        cnt++;
    }
    if(cnt==n) return false;
    return true;
}


// Method - 2 (partially correct)
#include<bits/stdc++.h>
using namespace std;

bool isCycle(int node, vector<int> adj[], int vis[], int dfsvis[]){
  vis[node] = 1; dfsvis[node] = 1;

  for(auto it : adj[node]){
    if(!vis[it]){
      if(isCycle(it, adj, vis, dfsvis)) return true;
    }
    else if(dfsvis[it]) return true;
  }
  dfsvis[node] = 0;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // creating adjacency list from edges
  vector<int> adj[n+1];
  // for(int i=0; i<n; i++){
  //   adj[edges[i][0]].push_back(edges[i][1]);
  //   adj[edges[0][i]].push_back(edges[i][0]);
  // }
  for(int i = 0; i < edges.size(); i++) {
    adj[edges[i].first].push_back(edges[i].second);
  }

  // create two visited arrays
  int vis[n], dfsvis[n];
  // set them both to zero
  memset(vis, 0, sizeof vis);
  memset(dfsvis, 0, sizeof dfsvis);

  for(int i=1; i<=n; i++){
    if(!vis[i]){
      if(isCycle(i, adj, vis, dfsvis)){
        return true;
      }
    }
  }
  return false;
}
