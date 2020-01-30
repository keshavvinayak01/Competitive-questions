#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> edges, int start, bool* visited) {
    queue<int> pendingVertices;
    
    pendingVertices.push(start);
    visited[start] = true;

    while(!pendingVertices.empty()) {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        if(edges[currentVertex].size() > 0) {
            for(int i = 0 ; i < edges[currentVertex].size(); i++) {
                int nextVertex = edges[currentVertex][i]; 
                if(!visited[nextVertex]) {
                    pendingVertices.push(nextVertex);
                    visited[nextVertex] = true;
                }
            }
        }
    }
}

int getNumberComponents(vector<vector<int>> edges, int n, bool* destroyed) {
    bool* visited = new bool[n];
    int components = 0;
    for(int i = 0 ; i < n ; i++) {
        if(!destroyed[i] && !visited[i]) {
            bfs(edges, i, visited);
            
            components++;
        }
    }
    delete[] visited;
    return components;
}

int getMaxComponents(int leaf, vector<vector<int>> reversedEdges, int n, vector<vector<int>> edges) {
    int current = leaf;
    bool destroyed[n];
    for(int i = 0 ; i < n ; i++) destroyed[i] = 0;
    while(reversedEdges[current].size() != 0) {
        destroyed[current] = 1;
        current = reversedEdges[current][0];
    }
    destroyed[0] = 1;
    for(int i = 0 ; i < n ; i++) {
        if(destroyed[i]) {
            while(edges[i].size() > 0) edges[i].pop_back();
        }
    }
    return getNumberComponents(edges, n, destroyed);
    
}   

int maxComponents(vector<vector<int>> edges, bool* isLeaf, int n, vector<vector<int>> reversedEdges) {
    int ans = -1;
    for(int i = 0 ; i < n ; i++) {
        if(isLeaf[i]) {
            ans = max(ans, getMaxComponents(i, reversedEdges, n, edges));
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges(n);
    vector<vector<int>> reversedEdges(n);

    for(int i = 0 ; i < n-1 ; i++) {
        int a, b;
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        reversedEdges[b-1].push_back(a-1);
    }       

    bool* isLeaf = new bool[n];
    for(int i = 0 ; i < n ; i++) {
        if(edges[i].size() == 0) {
            isLeaf[i] = true;
        }
    }
    
    cout << maxComponents(edges, isLeaf, n, reversedEdges) << endl;
    delete[] isLeaf;
    return 0;
}