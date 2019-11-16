#include<bits/stdc++.h>
using namespace std;

void DFS(bool** graph, int n, int start, bool* visited) {
    visited[start] = true;
    for(int i = 0; i < n; i++) {
        if(i == start) continue;
        if(graph[start][i]) {
            if(visited[i]) continue;
            DFS(graph, n, i, visited);
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    bool** graph = new bool*[n];
    for(int i= 0 ; i < n; i++) graph[i] = new bool[n];
    
    for(int i = 0 ; i < e; i++) {
        int f, e;
        cin >> f >> e;
        graph[f][e] = true;
        graph[e][f] = true;
    }
    bool* visited = new bool[n];
    for(int i = 0 ; i < n ; i++) visited[i] = false;
    DFS(graph, n, 0, visited);
    for(int i = 0 ; i < n ; i++) {
        if(!visited[i]) {
            cout << "false" << endl;
            return 0;
        }
    }
    cout << "true" << endl;
    return 0;
}