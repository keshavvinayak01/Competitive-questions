#include<bits/stdc++.h>
using namespace std;

int getShortestPath(vector<int>* edges, int n) {
    bool* visited = new bool[n];
    for(int i = 0; i < n; i++) visited[i] = false;

    queue<int> pendingVertices;
    pendingVertices.push(0);
    
    visited[0] = true;
    int currentLevel = 0;
    
    while(!pendingVertices.empty()) {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        visited[currentVertex] = true;
        
        for(int i = 0 ; i < edges[currentVertex].size(); i++) {
            int vertex = edges[currentVertex][i];
            if(vertex == n-1) {
                return ++currentLevel;
            }
            if(!visited[vertex]) {
                pendingVertices.push(vertex);
                visited[vertex] = true;
            }
        }
        currentLevel++;
    }
    return n-1;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m ;
        cin >> n >> m;
        vector<int>* edges = new vector<int>[n];
        
        for(int i = 0 ; i < m ; i++) {
            int a, b;
            cin >> a >> b;
            edges[a-1].push_back(b-1);
            edges[b-1].push_back(a-1);
        }
        cout << getShortestPath(edges, n) << endl;
    }
    return 0;
}