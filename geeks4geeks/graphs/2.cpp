/*
    Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
    A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool BFS(int x, vector<int> adj[], bool visited[], int nodes) {
        stack<int> visList;
        int curr, visCount = 0;
        visList.push(x);
        
        while(!visList.empty()) {
            curr = visList.top();
            visList.pop();
            visited[curr] = true;
            visCount++;
            
            for(int i = 0 ; i < adj[curr].size(); i++)
                if(!visited[adj[curr][i]])
                    visList.push(adj[curr][i]);
            
        }
        return visCount == nodes;
    }
	int findMotherVertex(int V, vector<int>adj[]){
	    // Code here
        int inEdges[V];
        bool visited[V], isMother;
        
        memset(inEdges, 0, V * sizeof(int));
        for(int i = 0 ;  i < V ; i++) {
            if(BFS(i, adj, visited, V))
                return i;
        }
        return -1;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends