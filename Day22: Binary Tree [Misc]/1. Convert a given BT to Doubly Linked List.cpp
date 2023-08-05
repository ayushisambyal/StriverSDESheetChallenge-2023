#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
void dfs(graphNode *node, graphNode *copy, unordered_map<int, graphNode*> &vis){
    vis[copy->data] = copy;
    for(auto it : node->neighbours){
        if(vis.find(it->data) == vis.end()){ // Check if the node is not visited
            graphNode *newnode = new graphNode(it->data);
            copy->neighbours.push_back(newnode);
            dfs(it, newnode, vis);
        }
        else{ // The node is already visited
            copy->neighbours.push_back(vis[it->data]);
        }
    }
}

graphNode *cloneGraph(graphNode *node)
{
    if(node == NULL) return NULL;
    unordered_map<int, graphNode*> vis; // Use unordered_map for O(1) lookup
    graphNode *copy = new graphNode(node->data);
    dfs (node, copy, vis);
    return copy; 
}
