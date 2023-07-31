#include <vector>
#include <stack>
using namespace std;

void tarjanDFS(int node, vector<vector<int>>& adjList, vector<int>& ids, vector<int>& low, vector<bool>& onStack, stack<int>& st, vector<vector<int>>& SCCs, int& id) {
    st.push(node);
    onStack[node] = true;
    ids[node] = low[node] = id++;
    
    for (int nei : adjList[node]) {
        if (ids[nei] == -1) {
            tarjanDFS(nei, adjList, ids, low, onStack, st, SCCs, id);
        }
        if (onStack[nei]) {
            low[node] = min(low[node], low[nei]);
        }
    }
    
    if (ids[node] == low[node]) {
        vector<int> SCC;
        while (!st.empty()) {
            int cur = st.top();
            st.pop();
            onStack[cur] = false;
            SCC.push_back(cur);
            if (cur == node) break;
        }
        SCCs.push_back(SCC);
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> SCCs;
    vector<vector<int>> adjList(n);
    for (vector<int>& edge : edges) {
        adjList[edge[0]].push_back(edge[1]);
    }
    
    vector<int> ids(n, -1), low(n);
    vector<bool> onStack(n, false);
    stack<int> st;
    int id = 0;
    
    for (int i = 0; i < n; ++i) {
        if (ids[i] == -1) {
            tarjanDFS(i, adjList, ids, low, onStack, st, SCCs, id);
        }
    }
    
    return SCCs;
}
