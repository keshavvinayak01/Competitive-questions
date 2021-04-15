/*
Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach to find the DFS traversal of the graph starting from the 0th vertex from 
left to right according to the graph..
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
    void DFS(int curr, vector<int> &soln, vector<int> adj[], int V, bool visited[]) {
        visited[curr] = true;
        soln.push_back(curr);
        for(auto x : adj[curr]) {
            if(!visited[x])
                DFS(x, soln, adj, V, visited);
        }
    }
    
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    // Code here
	    vector<int> soln;
	    bool visited[V];
	    memset(visited, false, V * sizeof(bool));
	    DFS(0, soln, adj, V, visited);
	    return soln;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends